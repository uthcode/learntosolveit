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

/* Regular expression objects */
/* This needs V8 or Henry Spencer's regexp! */

#include "allobjects.h"
#include "modsupport.h"

#include "regexp.h"

static object *RegexpError;    /* Exception */

typedef struct {
       OB_HEAD
       object *re_string;      /* The string (for printing) */
       regexp *re_prog;        /* The compiled regular expression */
} regexpobject;

/* Andrew Dalke, 27 March 2009, replaced 'extern' with 'static' */
/*extern typeobject Regexptype;*/  /* Really static, forward */
static typeobject Regexptype;

static regexpobject *
newregexpobject(string, prog)
       object *string;
       regexp *prog;
{
       regexpobject *re;
       re = NEWOBJ(regexpobject, &Regexptype);
       if (re != NULL) {
               XINCREF(string);
               re->re_string = string;
               re->re_prog = prog;
       }
       return re;
}

/* Regexp methods */

static void
regexp_dealloc(re)
       regexpobject *re;
{
       XDECREF(re->re_string);
       XDEL(re->re_prog);
       DEL(re);
}

static object *
makeresult(prog, buffer)
       regexp *prog;
       char *buffer;
{
       int n;
       object *v;
       /* Count substrings found, including \0, the main one */
       for (n = 0; n < 10 && prog->startp[n] != NULL; n++)
               ;
       v = newtupleobject(n);
       if (v != NULL) {
               int i;
               for (i = 0; i < n; i++) {
                       object *w, *u;
                       long start, end;
                       start = prog->startp[i] - buffer;
                       end = prog->endp[i] - buffer;
                       if (    (w = newtupleobject(2)) == NULL ||
                               (u = newintobject(start)) == NULL ||
                               settupleitem(w, 0, u) != 0 ||
                               (u = newintobject(end)) == NULL ||
                               settupleitem(w, 1, u) != 0) {
                               XDECREF(w);
                               DECREF(v);
                               return NULL;
                       }
                       settupleitem(v, i, w);
               }
       }
       return v;
}

static object *
regexp_exec(re, args)
       regexpobject *re;
       object *args;
{
       object *v;
       char *buffer;
       int offset;
       if (args != NULL && is_stringobject(args)) {
               v = args;
               offset = 0;
       }
       else if (!getstrintarg(args, &v, &offset))
               return NULL;
       buffer = getstringvalue(v);
#ifndef MULTILINE
#define reglexec(prog, str, offset) regexec((prog), (str)+(offset))
#endif
       if (!reglexec(re->re_prog, buffer, offset))
               return newtupleobject(0);
       return makeresult(re->re_prog, buffer);
}

static struct methodlist regexp_methods[] = {
       "exec",               regexp_exec,
       {NULL,          NULL}           /* sentinel */
};

static object *
regexp_getattr(re, name)
       regexpobject *re;
       char *name;
{
       return findmethod(regexp_methods, (object *)re, name);
}

static typeobject Regexptype = {
       OB_HEAD_INIT(&Typetype)
       0,                      /*ob_size*/
       "regexp",             /*tp_name*/
       sizeof(regexpobject),   /*tp_size*/
       0,                      /*tp_itemsize*/
       /* methods */
       regexp_dealloc,         /*tp_dealloc*/
       0,                      /*tp_print*/
       regexp_getattr,         /*tp_getattr*/
       0,                      /*tp_setattr*/
       0,                      /*tp_compare*/
       0,                      /*tp_repr*/
};

void
regerror(str)
       char *str;
{
       err_setstr(RegexpError, str);
}

static object *
regexp_compile(self, args)
       object *self;
       object *args;
{
       object *string;
       regexp *prog;
       if (!getstrarg(args, &string))
               return NULL;
       prog = regcomp(getstringvalue(string));
       if (prog == NULL)
               return NULL;    /* regerror() has called err_seterr() */
       return (object *)newregexpobject(string, prog);
}

static struct methodlist regexp_global_methods[] = {
       {"compile",   regexp_compile},
       {NULL,          NULL}           /* sentinel */
};

initregexp()
{
       object *m, *d;

       m = initmodule("regexp", regexp_global_methods);
       d = getmoduledict(m);

       /* Initialize regexp.error exception */
       RegexpError = newstringobject("regexp.error");
       if (RegexpError == NULL || dictinsert(d, "error", RegexpError) != 0)
               fatal("can't define regexp.error");
}
