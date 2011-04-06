/***********************************************************
Copyright 1991 by Stichting Mathematisch Centrum, Amsterdam, The
Netherlands.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation, and that the names of Stichting Mathematisch
Centrum or CWI not be used in advertising or publicity pertaining to
distribution of the software without specific, written prior permission.

STICHTING MATHEMATISCH CENTRUM DISCLAIMS ALL WARRANTIES WITH REGARD TO
THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS, IN NO EVENT SHALL STICHTING MATHEMATISCH CENTRUM BE LIABLE
FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

******************************************************************/

/* Amoeba module implementation */

/* Amoeba includes */
#include <amoeba.h>
#include <cmdreg.h>
#include <stdcom.h>
#include <stderr.h>
#include <caplist.h>
#include <server/bullet/bullet.h>
#include <server/tod/tod.h>
#include <module/name.h>
#include <module/direct.h>
#include <module/mutex.h>
#include <module/prv.h>
#include <module/stdcmd.h>

/* C includes */
#include <stdlib.h>
#include <ctype.h>

/* POSIX includes */
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Python includes */
#include "allobjects.h"
#include "modsupport.h"
#include "sc_global.h"
#include "stubcode.h"

extern char *err_why();
extern char *ar_cap();

#define STUBCODE       "+stubcode"

static object *AmoebaError;
object *StubcodeError;

static object *sc_dict;

/* Module initialization */

extern struct methodlist amoeba_methods[]; /* Forward */
extern object *convertcapv(); /* Forward */

static void
ins(d, name, v)
       object *d;
       char *name;
       object *v;
{
       if (v == NULL || dictinsert(d, name, v) != 0)
               fatal("can't initialize amoeba module");
}

void
initamoeba()
{
       object *m, *d, *v;

       m = initmodule("amoeba", amoeba_methods);
       d = getmoduledict(m);

       /* Define capv */
       v = convertcapv();
       ins(d, "capv", v);
       DECREF(v);

       /* Set timeout */
       timeout((interval)2000);

       /* Initialize amoeba.error exception */
       AmoebaError = newstringobject("amoeba.error");
       ins(d, "error", AmoebaError);
       StubcodeError = newstringobject("amoeba.stubcode_error");
       ins(d, "stubcode_error", StubcodeError);
       sc_dict = newdictobject();
}


/* Set an Amoeba-specific error, and return NULL */

object *
amoeba_error(err)
       errstat err;
{
       object *v = newtupleobject(2);
       if (v != NULL) {
               settupleitem(v, 0, newintobject((long)err));
               settupleitem(v, 1, newstringobject(err_why(err)));
       }
       err_setval(AmoebaError, v);
       if (v != NULL)
               DECREF(v);
       return NULL;
}


/* Capability object implementation */

extern typeobject Captype; /* Forward */

#define is_capobject(v) ((v)->ob_type == &Captype)

typedef struct {
       OB_HEAD
       capability ob_cap;
} capobject;

object *
newcapobject(cap)
       capability *cap;
{
       capobject *v = NEWOBJ(capobject, &Captype);
       if (v == NULL)
               return NULL;
       v->ob_cap = *cap;
       return (object *)v;
}

getcapability(v, cap)
       object *v;
       capability *cap;
{

       if (!is_capobject(v))
               return err_badarg();
       *cap = ((capobject *)v)->ob_cap;
       return 0;
}

/*
 *     is_capobj exports the is_capobject macro to the stubcode modules
 */

int
is_capobj(v)
       object *v;
{

       return is_capobject(v);
}

/* Methods */

static void
capprint(v, fp, flags)
       capobject *v;
       FILE *fp;
       int flags;
{
       /* XXX needs lock when multi-threading */
       fputs(ar_cap(&v->ob_cap), fp);
}

static object *
caprepr(v)
       capobject *v;
{
       /* XXX needs lock when multi-threading */
       return newstringobject(ar_cap(&v->ob_cap));
}

extern object *sc_interpreter();

extern struct methodlist cap_methods[]; /* Forward */

object *
sc_makeself(cap, stubcode, name)
       object *cap, *stubcode;
       char *name;
{
       object *sc_name, *sc_self;

       sc_name = newstringobject(name);
       if (sc_name == NULL)
               return NULL;
       sc_self = newtupleobject(3);
       if (sc_self == NULL) {
               DECREF(sc_name);
               return NULL;
       }
       if (settupleitem(sc_self, NAME, sc_name) != 0) {
               DECREF(sc_self);
               return NULL;
       }
       INCREF(cap);
       if (settupleitem(sc_self, CAP, cap) != 0) {
               DECREF(sc_self);
               return NULL;
       }
       INCREF(stubcode);
       if (settupleitem(sc_self, STUBC, stubcode) != 0) {
               DECREF(sc_self);
               return NULL;
       }
       return sc_self;
}


static void
swapcode(code, len)
       char *code;
       int len;
{
       int i = sizeof(TscOperand);
       TscOpcode opcode;
       TscOperand operand;

       while (i < len) {
               memcpy(&opcode, &code[i], sizeof(TscOpcode));
               SwapOpcode(opcode);
               memcpy(&code[i], &opcode, sizeof(TscOpcode));
               i += sizeof(TscOpcode);
               if (opcode & OPERAND) {
                       memcpy(&operand, &code[i], sizeof(TscOperand));
                       SwapOperand(operand);
                       memcpy(&code[i], &operand, sizeof(TscOperand));
                       i += sizeof(TscOperand);
               }
       }
}

object *
sc_findstubcode(v, name)
       object *v;
       char *name;
{
       int fd, fsize;
       char *fname, *buffer;
       struct stat statbuf;
       object *sc_stubcode, *ret;
       TscOperand sc_magic;

       /*
        *   Only look in the current directory for now.
        */
       fname = malloc(strlen(name) + 4);
       if (fname == NULL) {
               return err_nomem();
       }
       sprintf(fname, "%s.sc", name);
       if ((fd = open(fname, O_RDONLY)) == -1) {
               extern int errno;

               if (errno == 2) {
                       /*
                       **      errno == 2 is file not found.
                       */
                       err_setstr(NameError, fname);
                       return NULL;
               }
               free(fname);
               return err_errno(newstringobject(name));
       }
       fstat(fd, &statbuf);
       fsize = (int)statbuf.st_size;
       buffer = malloc(fsize);
       if (buffer == NULL) {
               free(fname);
               close(fd);
               return err_nomem();
       }
       if (read(fd, buffer, fsize) != fsize) {
               close(fd);
               free(fname);
               return err_errno(newstringobject(name));
       }
       close(fd);
       free(fname);
       memcpy(&sc_magic, buffer, sizeof(TscOperand));
       if (sc_magic != SC_MAGIC) {
               SwapOperand(sc_magic);
               if (sc_magic != SC_MAGIC) {
                       free(buffer);
                       return NULL;
               } else {
                       swapcode(buffer, fsize);
               }
       }
       sc_stubcode = newsizedstringobject(     &buffer[sizeof(TscOperand)],
                                               fsize - sizeof(TscOperand));
       free(buffer);
       if (sc_stubcode == NULL) {
               return NULL;
       }
       if (dictinsert(sc_dict, name, sc_stubcode) != 0) {
               DECREF(sc_stubcode);
               return NULL;
       }
       DECREF(sc_stubcode); /* XXXX */
       sc_stubcode = sc_makeself(v, sc_stubcode, name);
       if (sc_stubcode == NULL) {
               return NULL;
       }
       return sc_stubcode;
}

object *
capgetattr(v, name)
       capobject *v;
       char *name;
{
       object *sc_method, *sc_stubcodemethod;

       if (sc_dict == NULL) {
               /*
               **      For some reason the dictionary has not been
               **      initialized.  Try to find one of the built in
               **      methods.
               */
               return findmethod(cap_methods, (object *)v, name);
       }
       sc_stubcodemethod = dictlookup(sc_dict, name);
       if (sc_stubcodemethod != NULL) {
               /*
               **      There is a stubcode method in the dictionary.
               **      Execute the stubcode interpreter with the right
               **      arguments.
               */
               object *self, *ret;

               self = sc_makeself((object *)v, sc_stubcodemethod, name);
               if (self == NULL) {
                       return NULL;
               }
               ret = findmethod(cap_methods, self, STUBCODE);
               DECREF(self);
               return ret;
       }
       err_clear();
       sc_method = findmethod(cap_methods, (object *)v, name);
       if (sc_method == NULL) {
               /*
               **      The method is not built in and not in the
               **      dictionary. Try to find it as a stubcode file.
               */
               object *self, *ret;

               err_clear();
               self = sc_findstubcode((object *)v, name);
               if (self == NULL) {
                       return NULL;
               }
               ret = findmethod(cap_methods, self, STUBCODE);
               DECREF(self);
               return ret;
       }
       return sc_method;
}

int
capcompare(v, w)
       capobject *v, *w;
{
       int cmp = bcmp((char *)&v->ob_cap.cap_port,
                                       (char *)&w->ob_cap, PORTSIZE);
       if (cmp != 0)
               return cmp;
       return prv_number(&v->ob_cap.cap_priv) -
                                       prv_number(&w->ob_cap.cap_priv);
}

static typeobject Captype = {
       OB_HEAD_INIT(&Typetype)
       0,
       "capability",
       sizeof(capobject),
       0,
       free,           /*tp_dealloc*/
       capprint,       /*tp_print*/
       capgetattr,     /*tp_getattr*/
       0,              /*tp_setattr*/
       capcompare,     /*tp_comp
are*/
       caprepr,        /*tp_repr*/
       0,              /*tp_as_number*/
       0,              /*tp_as_sequence*/
       0,              /*tp_as_mapping*/
};


/* Return a dictionary corresponding to capv */

extern struct caplist *capv;

static object *
convertcapv()
{
       object *d;
       struct caplist *c;
       d = newdictobject();
       if (d == NULL)
               return NULL;
       if (capv == NULL)
               return d;
       for (c = capv; c->cl_name != NULL; c++) {
               object *v = newcapobject(c->cl_cap);
               if (v == NULL || dictinsert(d, c->cl_name, v) != 0) {
                       DECREF(d);
                       return NULL;
               }
               DECREF(v);
       }
       return d;
}


/* Strongly Amoeba-specific argument handlers */

static int
getcaparg(v, a)
       object *v;
       capability *a;
{
       if (v == NULL || !is_capobject(v))
               return err_badarg();
       *a = ((capobject *)v) -> ob_cap;
       return 1;
}

static int
getstrcapargs(v, a, b)
       object *v;
       object **a;
       capability *b;
{
       if (v == NULL || !is_tupleobject(v) || gettuplesize(v) != 2)
               return err_badarg();
       return getstrarg(gettupleitem(v, 0), a) &&
               getcaparg(gettupleitem(v, 1), b);
}


/* Amoeba methods */

static object *
amoeba_name_lookup(self, args)
       object *self;
       object *args;
{
       object *name;
       capability cap;
       errstat err;
       if (!getstrarg(args, &name))
               return NULL;
       err = name_lookup(getstringvalue(name), &cap);
       if (err != STD_OK)
               return amoeba_error(err);
       return newcapobject(&cap);
}

static object *
amoeba_name_append(self, args)
       object *self;
       object *args;
{
       object *name;
       capability cap;
       errstat err;
       if (!getstrcapargs(args, &name, &cap))
               return NULL;
       err = name_append(getstringvalue(name), &cap);
       if (err != STD_OK)
               return amoeba_error(err);
       INCREF(None);
       return None;
}

static object *
amoeba_name_replace(self, args)
       object *self;
       object *args;
{
       object *name;
       capability cap;
       errstat err;
       if (!getstrcapargs(args, &name, &cap))
               return NULL;
       err = name_replace(getstringvalue(name), &cap);
       if (err != STD_OK)
               return amoeba_error(err);
       INCREF(None);
       return None;
}

static object *
amoeba_name_delete(self, args)
       object *self;
       object *args;
{
       object *name;
       errstat err;
       if (!getstrarg(args, &name))
               return NULL;
       err = name_delete(getstringvalue(name));
       if (err != STD_OK)
               return amoeba_error(err);
       INCREF(None);
       return None;
}

static object *
amoeba_timeout(self, args)
       object *self;
       object *args;
{
       int i;
       object *v;
       interval tout;
       if (!getintarg(args, &i))
               return NULL;
       tout = timeout((interval)i);
       v = newintobject((long)tout);
       if (v == NULL)
               timeout(tout);
       return v;
}

static struct methodlist amoeba_methods[] = {
       {"name_append",               amoeba_name_append},
       {"name_delete",               amoeba_name_delete},
       {"name_lookup",               amoeba_name_lookup},
       {"name_replace",      amoeba_name_replace},
       {"timeout",           amoeba_timeout},
       {NULL,                  NULL}                   /* Sentinel */
};

/* Capability methods */

static object *
cap_b_size(self, args)
       capobject *self;
       object *args;
{
       errstat err;
       b_fsize size;
       if (!getnoarg(args))
               return NULL;
       err = b_size(&self->ob_cap, &size);
       if (err != STD_OK)
               return amoeba_error(err);
       return newintobject((long)size);
}

static object *
cap_b_read(self, args)
       capobject *self;
       object *args;
{
       errstat err;
       char *buf;
       object *v;
       long offset, size;
       b_fsize nread;
       if (!getlonglongargs(args, &offset, &size))
               return NULL;
       buf = malloc((unsigned int)size);
       if (buf == NULL) {
               return err_nomem();
       }
       err = b_read(&self->ob_cap, (b_fsize)offset, buf, (b_fsize)size,
                                                               &nread);
       if (err != STD_OK) {
               free(buf);
               return amoeba_error(err);
       }
       v = newsizedstringobject(buf, (int)nread);
       free(buf);
       return v;
}

static object *
cap_dir_lookup(self, args)
       capobject *self;
       object *args;
{
       object *name;
       capability cap;
       errstat err;
       if (!getstrarg(args, &name))
               return NULL;
       err = dir_lookup(&self->ob_cap, getstringvalue(name), &cap);
       if (err != STD_OK)
               return amoeba_error(err);
       return newcapobject(&cap);
}

static object *
cap_dir_append(self, args)
       capobject *self;
       object *args;
{
       object *name;
       capability cap;
       errstat err;
       if (!getstrcapargs(args, &name, &cap))
               return NULL;
       err = dir_append(&self->ob_cap, getstringvalue(name), &cap);
       if (err != STD_OK)
               return amoeba_error(err);
       INCREF(None);
       return None;
}

static object *
cap_dir_delete(self, args)
       capobject *self;
       object *args;
{
       object *name;
       errstat err;
       if (!getstrarg(args, &name))
               return NULL;
       err = dir_delete(&self->ob_cap, getstringvalue(name));
       if (err != STD_OK)
               return amoeba_error(err);
       INCREF(None);
       return None;
}

static object *
cap_dir_replace(self, args)
       capobject *self;
       object *args;
{
       object *name;
       capability cap;
       errstat err;
       if (!getstrcapargs(args, &name, &cap))
               return NULL;
       err = dir_replace(&self->ob_cap, getstringvalue(name), &cap);
       if (err != STD_OK)
               return amoeba_error(err);
       INCREF(None);
       return None;
}

static object *
cap_dir_list(self, args)
       capobject *self;
       object *args;
{
       errstat err;
       struct dir_open *dd;
       object *d;
       char *name;
       if (!getnoarg(args))
               return NULL;
       if ((dd = dir_open(&self->ob_cap)) == NULL)
               return amoeba_error(STD_COMBAD);
       if ((d = newlistobject(0)) == NULL) {
               dir_close(dd);
               return NULL;
       }
       while ((name = dir_next(dd)) != NULL) {
               object *v;
               v = newstringobject(name);
               if (v == NULL) {
                       DECREF(d);
                       d = NULL;
                       break;
               }
               if (addlistitem(d, v) != 0) {
                       DECREF(v);
                       DECREF(d);
                       d = NULL;
                       break;
               }
               DECREF(v);
       }
       dir_close(dd);
       return d;
}

object *
cap_std_info(self, args)
       capobject *self;
       object *args;
{
       char buf[256];
       errstat err;
       int n;
       if (!getnoarg(args))
               return NULL;
       err = std_info(&self->ob_cap, buf, sizeof buf, &n);
       if (err != STD_OK)
               return amoeba_error(err);
       return newsizedstringobject(buf, n);
}

object *
cap_tod_gettime(self, args)
       capobject *self;
       object *args;
{
       header h;
       errstat err;
       bufsize n;
       long sec;
       int msec, tz, dst;
       if (!getnoarg(args))
               return NULL;
       h.h_port = self->ob_cap.cap_port;
       h.h_priv = self->ob_cap.cap_priv;
       h.h_command = TOD_GETTIME;
       n = trans(&h, NILBUF, 0, &h, NILBUF, 0);
       if (ERR_STATUS(n))
               return amoeba_error(ERR_CONVERT(n));
       tod_decode(&h, &sec, &msec, &tz, &dst);
       return newintobject(sec);
}

object *
cap_tod_settime(self, args)
       capobject *self;
       object *args;
{
       header h;
       errstat err;
       bufsize n;
       long sec;
       if (!getlongarg(args, &sec))
               return NULL;
       h.h_port = self->ob_cap.cap_port;
       h.h_priv = self->ob_cap.cap_priv;
       h.h_command = TOD_SETTIME;
       tod_encode(&h, sec, 0, 0, 0);
       n = trans(&h, NILBUF, 0, &h, NILBUF, 0);
       if (ERR_STATUS(n))
               return amoeba_error(ERR_CONVERT(n));
       INCREF(None);
       return None;
}

static struct methodlist cap_methods[] = {
       { STUBCODE,             sc_interpreter},
       {"b_read",            cap_b_read},
       {"b_size",            cap_b_size},
       {"dir_append",                cap_dir_append},
       {"dir_delete",                cap_dir_delete},
       {"dir_list",          cap_dir_list},
       {"dir_lookup",                cap_dir_lookup},
       {"dir_replace",               cap_dir_replace},
       {"std_info",          cap_std_info},
       {"tod_gettime",               cap_tod_gettime},
       {"tod_settime",               cap_tod_settime},
       {NULL,                  NULL}                   /* Sentinel */
};
