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

/* Panel module.
   Interface to the NASA Ames "panel library" for the SGI Graphics Library
   by David Tristram.

   NOTE: the panel library dumps core if you don't create a window before
   calling pnl.mkpanel().  A call to gl.winopen() suffices.
   If you don't want a window to be created, call gl.noport() before
   gl.winopen().
*/

#include <gl.h>
#include <device.h>
#include <panel.h>

#include "allobjects.h"
#include "import.h"
#include "modsupport.h"
#include "cgensupport.h"


/* The offsetof() macro calculates the offset of a structure member
   in its structure.  Unfortunately this cannot be written down portably,
   hence it is standardized by ANSI C.  For pre-ANSI C compilers,
   we give a version here that works usually (but watch out!): */

#ifndef offsetof
#define offsetof(type, member) ( (int) & ((type*)0) -> member )
#endif


/* Panel objects */

typedef struct {
       OB_HEAD
       Panel *ob_panel;
       object *ob_paneldict;
} panelobject;

extern typeobject Paneltype; /* Really static, forward */

#define is_panelobject(v) ((v)->ob_type == &Paneltype)


/* Actuator objects */

typedef struct {
       OB_HEAD
       Actuator *ob_actuator;
} actuatorobject;

extern typeobject Actuatortype; /* Really static, forward */

#define is_actuatorobject(v) ((v)->ob_type == &Actuatortype)

static object *newactuatorobject(); /* Forward */


/* Since we allow different types of members than the functions from
   structmember.c, the memberlist stuff is replicated here.
   (Historically, it originated in this file and later became a generic
   feature.) */

/* An array of memberlist structures defines the name, type and offset
   of selected members of a C structure.  These can be read by
   panel_getmember() and set by panel_setmember() (except if their
   READONLY flag is set).  The array must be terminated with an entry
   whose name pointer is NULL. */

struct memberlist {
       char *name;
       int type;
       int offset;
       int readonly;
};

/* Types */
#define T_SHORT                0
#define T_DEVICE       T_SHORT
#define T_LONG         1
#define T_INT          T_LONG
#define T_BOOL         T_LONG
#define T_FLOAT                2
#define T_COORD                T_FLOAT
#define T_STRING       3
#define T_FUNC         4
#define T_ACTUATOR     5

/* Readonly flag */
#define READONLY       1
#define RO             READONLY                /* Shorthand */

static object *
panel_getmember(addr, mlist, name)
       char *addr;
       struct memberlist *mlist;
       char *name;
{
       object *v;
       register struct memberlist *l;

       for (l = mlist; l->name != NULL; l++) {
               if (strcmp(l->name, name) == 0) {
                       addr += l->offset;
                       switch (l->type) {
                       case T_SHORT:
                               v = newintobject((long) *(short*)addr);
                               break;
                       case T_LONG:
                               v = newintobject(*(long*)addr);
                               break;
                       case T_FLOAT:
                               v = newfloatobject(*(float*)addr);
                               break;
                       case T_STRING:
                               if (*(char**)addr == NULL) {
                                       INCREF(None);
                                       v = None;
                               }
                               else
                                       v = newstringobject(*(char**)addr);
                               break;
                       case T_ACTUATOR:
                               v = newactuatorobject(*(Actuator**)addr);
                               break;
                       default:
                               err_badarg();
                               v = NULL;
                       }
                       return v;
               }
       }
       err_setstr(NameError, name);
       return NULL;
}

/* Attempt to set a member.  Return: 0 if OK; 1 if not found; -1 if error */

static int
panel_setmember(addr, mlist, name, v)
       char *addr;
       struct memberlist *mlist;
       char *name;
       object *v;
{
       register struct memberlist *l;

       for (l = mlist; l->name != NULL; l++) {
               if (strcmp(l->name, name) == 0) {
                       if (l->readonly) {
                               err_setstr(TypeError, "read-only member");
                               return -1;
                       }
                       addr += l->offset;
                       switch (l->type) {
                       case T_SHORT:
                               if (!is_intobject(v)) {
                                       err_setstr(TypeError, "int expected");
                                       return -1;
                               }
                               *(short*)addr = getintvalue(v);
                               break;
                       case T_LONG:
                               if (!is_intobject(v)) {
                                       err_setstr(TypeError, "int expected");
                                       return -1;
                               }
                               *(long*)addr = getintvalue(v);
                               break;
                       case T_FLOAT:
                               if (is_intobject(v))
                                       *(float*)addr = getintvalue(v);
                               else if (is_floatobject(v))
                                       *(float*)addr = getfloatvalue(v);
                               else {
                                       err_setstr(TypeError,"float expected");
                                       return -1;
                               }
                               break;
                       case T_STRING:
                               /* XXX Should free(*(char**)addr) here
                                  but it's dangerous since we don't know
                                  if we set the label ourselves */
                               if (v == None)
                                       *(char**)addr = NULL;
                               else if (!is_stringobject(v)) {
                                       err_setstr(TypeError,
                                                       "string expected");
                                       return -1;
                               }
                               else
                                       *(char**)addr =
                                               strdup(getstringvalue(v));
                               break;
                       case T_ACTUATOR:
                               if (v == None)
                                       *(Actuator**)addr = NULL;
                               else if (!is_actuatorobject(v)) {
                                       err_setstr(TypeError,
                                                       "actuator expected");
                                       return -1;
                               }
                               else
                                       *(Actuator**)addr =
                                           ((actuatorobject *)v)->ob_actuator;
                               break;
                       default:
                               err_setstr(SystemError, "unknown member type");
                               return -1;
                       }
                       return 0; /* Found it */
               }
       }

       return 1; /* Not found */
}


/* Panel object methods */

static object *
panel_addpanel(self, args)
       panelobject *self;
       object *args;
{
       if (!getnoarg(args))
               return NULL;
       pnl_addpanel(self->ob_panel);
       INCREF(None);
       return None;
}

static object *
panel_endgroup(self, args)
       panelobject *self;
       object *args;
{
       if (!getnoarg(args))
               return NULL;
       pnl_endgroup(self->ob_panel);
       INCREF(None);
       return None;
}

static object *
panel_fixpanel(self, args)
       panelobject *self;
       object *args;
{
       if (!getnoarg(args))
               return NULL;
       pnl_fixpanel(self->ob_panel);
       INCREF(None);
       return None;
}

static object *
panel_strwidth(self, args)
       panelobject *self;
       object *args;
{
       object *v;
       double width;
       if (!getstrarg(args, &v))
               return NULL;
       width = pnl_strwidth(self->ob_panel, getstringvalue(v));
       return newfloatobject(width);
}

static struct methodlist panel_methods[] = {
       {"addpanel",          panel_addpanel},
       {"endgroup",          panel_endgroup},
       {"fixpanel",          panel_fixpanel},
       {"strwidth",          panel_strwidth},
       {NULL,                  NULL}           /* sentinel */
};

static object *
newpanelobject()
{
       panelobject *p;
       p = NEWOBJ(panelobject, &Paneltype);
       if (p == NULL)
               return NULL;
       p->ob_panel = pnl_mkpanel();
       if ((p->ob_paneldict = newdictobject()) == NULL) {
               DECREF(p);
               return NULL;
       }
       return (object *)p;
}

static void
panel_dealloc(p)
       panelobject *p;
{
       pnl_delpanel(p->ob_panel);
       if (p->ob_paneldict != NULL)
               DECREF(p->ob_paneldict);
       DEL(p);
}


/* Table of panel members */

#define PANOFF(member) offsetof(Panel, member)

static struct memberlist panel_memberlist[] = {
       {"id",                T_SHORT,        PANOFF(id),             READONLY},
       {"a",         T_ACTUATOR,     PANOFF(a),              READONLY},
       {"al",                T_ACTUATOR,     PANOFF(al),             READONLY},
       {"lastgroup", T_ACTUATOR,     PANOFF(lastgroup),      READONLY},

       {"active",    T_BOOL,         PANOFF(active)},
       {"selectable",        T_BOOL,         PANOFF(selectable)},

       {"x",         T_LONG,         PANOFF(x)},
       {"y",         T_LONG,         PANOFF(y)},
       {"w",         T_LONG,         PANOFF(w)},
       {"h",         T_LONG,         PANOFF(h)},

       {"minx",      T_COORD,        PANOFF(minx)},
       {"maxx",      T_COORD,        PANOFF(maxx)},
       {"miny",      T_COORD,        PANOFF(miny)},
       {"maxy",      T_COORD,        PANOFF(maxy)},

       {"cw",                T_COORD,        PANOFF(cw)},
       {"ch",                T_COORD,        PANOFF(ch)},

       {"gid",               T_LONG,         PANOFF(gid),            READONLY},
       {"usergid",   T_LONG,         PANOFF(usergid),        READONLY},

       {"vobj",      T_LONG,         PANOFF(vobj),           READONLY},
       {"ppu",               T_FLOAT,        PANOFF(ppu)},

       {"label",     T_STRING,       PANOFF(label)},

       /* Panel callbacks are not supported */

       {"visible",   T_BOOL,         PANOFF(visible)},
       {"somedirty", T_INT,          PANOFF(somedirty)},
       {"dirtycnt",  T_INT,          PANOFF(dirtycnt)},

       /* T_PANEL is not supported */
       /*
       {"next",      T_PANEL,        PANOFF(next),           READONLY},
       */

       {NULL,          0,              0}              /* Sentinel */
};

static object *
panel_getattr(p, name)
       panelobject *p;
       char *name;
{
       object *v;

       v = dictlookup(p->ob_paneldict, name);
       if (v != NULL) {
               INCREF(v);
               return v;
       }

       v = findmethod(panel_methods, (object *)p, name);
       if (v != NULL)
               return v;
       err_clear();
       return panel_getmember((char *)p->ob_panel, panel_memberlist, name);
}

static int
panel_setattr(p, name, v)
       panelobject *p;
       char *name;
       object *v;
{
       int err;

       /* We don't allow deletion of attributes */
       if (v == NULL) {
               err_setstr(TypeError, "read-only panel attribute");
               return -1;
       }
       err = panel_setmember((char *)p->ob_panel, panel_memberlist, name, v);
       if (err != 1)
               return err;
       return dictinsert(p->ob_paneldict, name, v);
}

static typeobject Paneltype = {
       OB_HEAD_INIT(&Typetype)
       0,                      /*ob_size*/
       "panel",              /*tp_name*/
       sizeof(panelobject),    /*tp_size*/
       0,                      /*tp_itemsize*/
       /* methods */
       panel_dealloc,          /*tp_dealloc*/
       0,                      /*tp_print*/
       panel_getattr,          /*tp_getattr*/
       panel_setattr,          /*tp_setattr*/
       0,                      /*tp_compare*/
       0,                      /*tp_repr*/
};


/* Descriptions of actuator-specific data members */

struct memberlist slider_spec[] = {
       {"mode",      T_INT,          offsetof(Slider, mode)},
       {"finefactor",        T_FLOAT,        offsetof(Slider, finefactor)},
       {"differentialfactor",
                       T_FLOAT,        offsetof(Slider, differentialfactor)},
       {"valsave",   T_FLOAT,        offsetof(Slider, valsave),      RO},
       {"wsave",     T_COORD,        offsetof(Slider, wsave)},
       {"bh",                T_COORD,        offsetof(Slider, bh)},
       {NULL}
};

#define palette_spec slider_spec

struct memberlist puck_spec[] = {
       /* Actuators already have members x and y, so the Puck's x and y
          have different names */
       {"puck_x",    T_FLOAT,        offsetof(Puck, x)},
       {"puck_y",    T_FLOAT,        offsetof(Puck, y)},
       {NULL}
};

struct memberlist dial_spec[] = {
       {"mode",      T_INT,          offsetof(Dial, mode)},
       {"finefactor",        T_FLOAT,        offsetof(Dial, finefactor)},
       {"valsave",   T_FLOAT,        offsetof(Dial, valsave),        RO},
       {"wsave",     T_COORD,        offsetof(Dial, wsave)},
       {"winds",     T_FLOAT,        offsetof(Dial, winds)},
       {NULL}
};

struct memberlist slideroid_spec[] = {
       {"mode",      T_INT,          offsetof(Slideroid, mode)},
       {"finemode",  T_BOOL,         offsetof(Slideroid, finemode)},
       {"resetmode", T_BOOL,         offsetof(Slideroid, resetmode)},
       /* XXX Can't do resettarget (pointer to float) */
       /* XXX This makes resetval pretty useless... */
       /*
       {"resetval",  T_FLOAT,        offsetof(Slideroid, resetval)},
       */
       {"valsave",   T_FLOAT,        offsetof(Slideroid, valsave),   RO},
       {"wsave",     T_COORD,        offsetof(Slideroid, wsave)},
       {NULL}
};

struct memberlist stripchart_spec[] = {
       {"firstpt",   T_INT,          offsetof(Stripchart, firstpt),  RO},
       {"lastpt",    T_INT,          offsetof(Stripchart, lastpt),   RO},
       {"Bind_Low",  T_BOOL,         offsetof(Stripchart, Bind_Low)},
       {"Bind_High", T_BOOL,         offsetof(Stripchart, Bind_High)},
       /* XXX Can't do y (array of floats) */
       {"lowlabel",  T_ACTUATOR,     offsetof(Stripchart, lowlabel), RO},
       {"highlabel", T_ACTUATOR,     offsetof(Stripchart, highlabel), RO},
       {NULL}
};

struct memberlist typein_spec[] = {
       /* Note: these should be readonly after the actuator is added
          to a panel */
       {"str",               T_STRING,       offsetof(Typein, str)},
       {"len",               T_INT,          offsetof(Typein, len)},
       {NULL}
};

struct memberlist typeout_spec[] = {
       {"mode",      T_INT,          offsetof(Typeout, mode)},
       /* XXX The buffer is managed by the actuator; but how do we
          add text? */
       {"buf",               T_STRING,       offsetof(Typeout, buf), READONLY},
       {"delimstr",  T_STRING,       offsetof(Typeout, delimstr)},
       {"start",     T_INT,          offsetof(Typeout, start)},
       {"dot",               T_INT,          offsetof(Typeout, dot)},
       {"mark",      T_INT,          offsetof(Typeout, mark)},
       {"col",               T_INT,          offsetof(Typeout, col)},
       {"lin",               T_INT,          offsetof(Typeout, lin)},
       {"len",               T_INT,          offsetof(Typeout, len)},
       {"size",      T_INT,          offsetof(Typeout, size)},
       {NULL}
};

struct memberlist mouse_spec[] = {
       /* Actuators already have members x and y, so the Mouse's x and y
          have different names */
       {"mouse_x",   T_FLOAT,        offsetof(Mouse, x)},
       {"mouse_y",   T_FLOAT,        offsetof(Mouse, y)},
       {NULL}
};

#define MULOFF(member) offsetof(Multislider, member)

struct memberlist multislider_spec[] = {
       {"mode",      T_INT,          MULOFF(mode)},
       {"n",         T_INT,          MULOFF(n)},
       {"finefactor",        T_FLOAT,        MULOFF(finefactor)},
       {"wsave",     T_COORD,        MULOFF(wsave)},
       {"sa",                T_ACTUATOR,     MULOFF(sa)},
       {"bh",                T_COORD,        MULOFF(bh)},
       {"clrx",      T_COORD,        MULOFF(clrx)},
       {"clry",      T_COORD,        MULOFF(clry)},
       {"clrw",      T_COORD,        MULOFF(clrw)},
       {"clrh",      T_COORD,        MULOFF(clrh)},
       /* XXX acttype? */
       {NULL}
};

/* XXX Still to do:
       Frame
       Icon
       Cycle
       Scroll
       Menu
*/

/* List of known actuator initializer functions */

struct {
       char *name;
       void (*func)();
       struct memberlist *spec;
} initializerlist[] = {
       {"analog_bar",                        pnl_analog_bar},
       {"analog_meter",              pnl_analog_meter},
       {"button",                    pnl_button},
       {"cycle",                     pnl_cycle},
       /* Doesn't exist: */
/*     {"dhslider",                  pnl_dhslider, slider_spec},     */
       {"dial",                      pnl_dial, dial_spec},
       {"down_arrow_button",         pnl_down_arrow_button},
       {"down_double_arrow_button",  pnl_down_double_arrow_button},
       {"dvslider",                  pnl_dvslider, slider_spec},
       {"filled_hslider",            pnl_filled_hslider, slider_spec},
       {"filled_slider",             pnl_filled_slider, slider_spec},
       {"filled_vslider",            pnl_filled_vslider, slider_spec},
       {"floating_puck",             pnl_floating_puck, puck_spec},
       {"frame",                     pnl_frame},
       {"graphframe",                        pnl_graphframe},
       {"hmultislider",              pnl_hmultislider, multislider_spec},
       {"hmultislider_bar",          pnl_hmultislider_bar},
       {"hmultislider_open_bar",     pnl_hmultislider_open_bar},
       {"hpalette",                  pnl_hpalette, palette_spec},
       {"hslider",                   pnl_hslider, slider_spec},
       {"icon",                      pnl_icon},
       {"icon_menu",                 pnl_icon_menu},
       {"label",                     pnl_label},
       {"left_arrow_button",         pnl_left_arrow_button},
       {"left_double_arrow_button",  pnl_left_double_arrow_button},
       {"menu",                      pnl_menu},
       {"menu_item",                 pnl_menu_item},
       {"meter",                     pnl_meter},
       {"mouse",                     pnl_mouse, mouse_spec},
       {"multislider",                       pnl_multislider, multislider_spec},
       {"multislider_bar",           pnl_multislider_bar},
       {"multislider_open_bar",      pnl_multislider_open_bar},
       {"palette",                   pnl_palette, palette_spec},
       {"puck",                      pnl_puck, puck_spec},
       {"radio_button",              pnl_radio_button},
       {"radio_check_button",                pnl_radio_check_button},
       {"right_arrow_button",                pnl_right_arrow_button},
       {"right_double_arrow_button", pnl_right_double_arrow_button},
       {"rubber_puck",                       pnl_rubber_puck, puck_spec},
       {"scale_chart",                       pnl_scale_chart, stripchart_spec},
       {"scroll",                    pnl_scroll},
       {"signal",                    pnl_signal},
       {"slider",                    pnl_slider, slider_spec},
       {"slideroid",                 pnl_slideroid, slideroid_spec},
       {"strip_chart",                       pnl_strip_chart, stripchart_spec},
       {"sub_menu",                  pnl_sub_menu},
       {"toggle_button",             pnl_toggle_button},
       {"typein",                    pnl_typein, typein_spec},
       {"typeout",                   pnl_typeout, typeout_spec},
       {"up_arrow_button",           pnl_up_arrow_button},
       {"up_double_arrow_button",    pnl_up_double_arrow_button},
       {"viewframe",                 pnl_viewframe},
       {"vmultislider",              pnl_vmultislider, multislider_spec},
       {"vmultislider_bar",          pnl_vmultislider_bar},
       {"vmultislider_open_bar",     pnl_vmultislider_open_bar},
       {"vpalette",                  pnl_vpalette, palette_spec},
       {"vslider",                   pnl_vslider, slider_spec},
       {"wide_button",                       pnl_wide_button},
       {NULL,                          NULL}           /* Sentinel */
};


/* Pseudo downfunc etc. */

static Actuator *down_pend, *active_pend, *up_pend;

static void
downfunc(a)
       Actuator *a;
{
       if (down_pend == NULL)
               down_pend = a;
}

static void
activefunc(a)
       Actuator *a;
{
       if (active_pend == NULL)
               active_pend = a;
}

static void
upfunc(a)
       Actuator *a;
{
       if (up_pend == NULL)
               up_pend = a;
}


/* Lay-out for the user data */

struct userdata {
       object *dict;   /* Dictionary object for additional attributes */
       struct memberlist *spec;        /* Actuator-specific members */
};


/* Create a new actuator; the actuator type is given as a string */

static Actuator *
makeactuator(name)
       char *name;
{
       Actuator *act;
       void (*initializer)() = NULL;
       int i;
       struct userdata *u;
       for (i = 0; initializerlist[i].name != NULL; i++) {
               if (strcmp(initializerlist[i].name, name) == 0) {
                       initializer = initializerlist[i].func;
                       break;
               }
       }
       if (initializerlist[i].name == NULL) {
               err_badarg();
               return NULL;
       }
       u = NEW(struct userdata, 1);
       if (u == NULL) {
               err_nomem();
               return NULL;
       }
       u->dict = NULL;
       u->spec = initializerlist[i].spec;
       act = pnl_mkact(initializer);
       act->u = (char *)u;
       act->downfunc = downfunc;
       act->activefunc = activefunc;
       act->upfunc = upfunc;
       return act;
}


/* Actuator objects methods */

static object *
actuator_addact(self, args)
       actuatorobject *self;
       object *args;
{
       Panel *p;
       if (!is_panelobject(args)) {
               err_badarg();
               return NULL;
       }
       p = ((panelobject *)args) -> ob_panel;
       pnl_addact(self->ob_actuator, p);
       INCREF(None);
       return None;
}

static object *
actuator_addsubact(self, args)
       actuatorobject *self;
       object *args;
{
       Actuator *a;
       if (!is_actuatorobject(args)) {
               err_badarg();
               return NULL;
       }
       a = ((actuatorobject *)args) -> ob_actuator;
       pnl_addsubact(self->ob_actuator, a);
       INCREF(None);
       return None;
}

static object *
actuator_delact(self, args)
       actuatorobject *self;
       object *args;
{
       Panel *p;
       if (!getnoarg(args))
               return NULL;
       pnl_delact(self->ob_actuator);
       INCREF(None);
       return None;
}

static object *
actuator_fixact(self, args)
       actuatorobject *self;
       object *args;
{
       Panel *p;
       if (!getnoarg(args))
               return NULL;
       pnl_fixact(self->ob_actuator);
       INCREF(None);
       return None;
}

static object *
actuator_tprint(self, args)
       actuatorobject *self;
       object *args;
{
       object *str;
       if (self->ob_actuator->type != PNL_TYPEOUT) {
               err_setstr(TypeError, "tprint for non-typeout panel");
               return NULL;
       }
       if (!getstrarg(args, &str))
               return NULL;
       tprint(self->ob_actuator, getstringvalue(str));
       /* XXX Can't turn tprint's errors into exceptions, sorry */
       INCREF(None);
       return None;
}

static struct methodlist actuator_methods[] = {
       {"addact",            actuator_addact},
       {"addsubact",         actuator_addsubact},
       {"delact",            actuator_delact},
       {"fixact",            actuator_fixact},
       {"tprint",            actuator_tprint},
       {NULL,                  NULL}           /* sentinel */
};

static object *
newactuatorobject(act)
       Actuator *act;
{
       actuatorobject *a;
       if (act == NULL) {
               INCREF(None);
               return None;
       }
       a = NEWOBJ(actuatorobject, &Actuatortype);
       if (a == NULL)
               return NULL;
       a->ob_actuator = act;
       return (object *)a;
}

static void
actuator_dealloc(a)
       actuatorobject *a;
{
       /* Do NOT delete the actuator; most actuator objects are created
          to hold a temporary reference to an actuator, like one gotten
          from pnl_dopanel(). */

       DEL(a);
}


/* Table of actuator members */

#define ACTOFF(member) offsetof(Actuator, member)

struct memberlist act_memberlist[] = {
       {"id",                T_SHORT,        ACTOFF(id),             READONLY},

       /* T_PANEL is not defined */
       /*
       {"p",         T_PANEL,        ACTOFF(p),              READONLY},
       */

       {"pa",                T_ACTUATOR,     ACTOFF(pa),             READONLY},
       {"ca",                T_ACTUATOR,     ACTOFF(ca),             READONLY},
       {"al",                T_ACTUATOR,     ACTOFF(al),             READONLY},
       {"na",                T_INT,          ACTOFF(na),             READONLY},
       {"type",      T_INT,          ACTOFF(type),           READONLY},
       {"active",    T_BOOL,         ACTOFF(active)},

       {"x",         T_COORD,        ACTOFF(x)},
       {"y",         T_COORD,        ACTOFF(y)},
       {"w",         T_COORD,        ACTOFF(w)},
       {"h",         T_COORD,        ACTOFF(h)},

       {"lx",                T_COORD,        ACTOFF(lx)},
       {"ly",                T_COORD,        ACTOFF(ly)},
       {"lw",                T_COORD,        ACTOFF(lw)},
       {"lh",                T_COORD,        ACTOFF(lh)},
       {"ld",                T_COORD,        ACTOFF(ld)},

       {"val",               T_FLOAT,        ACTOFF(val)},
       {"extval",    T_FLOAT,        ACTOFF(extval)},
       {"initval",   T_FLOAT,        ACTOFF(initval)},
       {"maxval",    T_FLOAT,        ACTOFF(maxval)},
       {"minval",    T_FLOAT,        ACTOFF(minval)},
       {"scalefactor",       T_FLOAT,        ACTOFF(scalefactor)},

       {"label",     T_STRING,       ACTOFF(label)},
       {"key",               T_DEVICE,       ACTOFF(key)},
       {"labeltype", T_INT,          ACTOFF(labeltype)},

       /* Internal callbacks are not supported;
          user callbacks are treated special! */

       {"dirtycnt",  T_INT,          ACTOFF(dirtycnt)},

       /* members u and data are accessed differently */

       {"automatic", T_BOOL,         ACTOFF(automatic)},
       {"selectable",        T_BOOL,         ACTOFF(selectable)},
       {"visible",   T_BOOL,         ACTOFF(visible)},
       {"beveled",   T_BOOL,         ACTOFF(beveled)},

       {"group",     T_ACTUATOR,     ACTOFF(group),          READONLY},
       {"next",      T_ACTUATOR,     ACTOFF(next),           READONLY},

       {NULL,          0,              0}              /* Sentinel */
};


/* Potential name conflicts between attributes are solved as follows.
   - Actuator-specific attributes always override generic attributes.
   - When reading, the dictionary has overrides everything else;
     when writing, everything else overrides the dictionary.
   - When reading, methods are tried last.
*/

static object *
actuator_getattr(a, name)
       actuatorobject *a;
       char *name;
{
       Actuator *act = a->ob_actuator;
       struct userdata *u = (struct userdata *) act->u;
       object *v;

       if (u != NULL) {
               /* 1. Try the dictionary */
               if (u->dict != NULL) {
                       v = dictlookup(u->dict, name);
                       if (v != NULL) {
                               INCREF(v);
                               return v;
                       }
               }

               /* 2. Try actuator-specific attributes */
               if (u->spec != NULL) {
                       v = panel_getmember(act->data, u->spec, name);
                       if (v != NULL)
                               return v;
                       err_clear();
               }
       }

       /* 3. Try generic actuator attributes */
       v = panel_getmember((char *)act, act_memberlist, name);
       if (v != NULL)
               return v;

       /* 4. Try methods */
       err_clear();
       return findmethod(actuator_methods, (object *)a, name);
}

static int
actuator_setattr(a, name, v)
       actuatorobject *a;
       char *name;
       object *v;
{
       Actuator *act = a->ob_actuator;
       struct userdata *u = (struct userdata *) act->u;
       int err;

       /* 0. We don't allow deletion of attributes */
       if (v == NULL) {
               err_setstr(TypeError, "read-only actuator attribute");
               return -1;
       }

       /* 1. Try actuator-specific attributes */
       if (u != NULL && u->spec != NULL) {
               err = panel_setmember(act->data, u->spec, name, v);
               if (err != 1)
                       return err;
       }

       /* 2. Try generic actuator attributes */
       err = panel_setmember((char *)act, act_memberlist, name, v);
       if (err != 1)
               return err;

       /* 3. Try the dictionary */
       if (u != NULL) {
               if (u->dict == NULL && (u->dict = newdictobject()) == NULL)
                       return NULL;
               return dictinsert(u->dict, name, v);
       }

       err_setstr(NameError, name);
       return -1;
}

static int
actuator_compare(v, w)
       actuatorobject *v, *w;
{
       long i = (long)v->ob_actuator;
       long j = (long)w->ob_actuator;
       return (i < j) ? -1 : (i > j) ? 1 : 0;
}

static typeobject Actuatortype = {
       OB_HEAD_INIT(&Typetype)
       0,                      /*ob_size*/
       "actuator",           /*tp_name*/
       sizeof(actuatorobject), /*tp_size*/
       0,                      /*tp_itemsize*/
       /* methods */
       actuator_dealloc,       /*tp_dealloc*/
       0,                      /*tp_print*/
       actuator_getattr,       /*tp_getattr*/
       actuator_setattr,       /*tp_setattr*/
       actuator_compare,       /*tp_compare*/
       0,                      /*tp_repr*/
};


/* The panel module itself */

static object *
module_mkpanel(self, args)
       object *self;
       object *args;
{
       if (!getnoarg(args))
               return NULL;
       return newpanelobject();
}

static object *
module_mkact(self, args)
       object *self;
       object *args;
{
       object *v;
       Actuator *a;
       if (!getstrarg(args, &v))
               return NULL;
       a = makeactuator(getstringvalue(v));
       if (a == NULL)
               return NULL;
       return newactuatorobject(a);
}

static object *
module_dopanel(self, args)
       object *self;
       object *args;
{
       Actuator *a;
       object *v, *w;
       if (!getnoarg(args))
               return NULL;
       a = pnl_dopanel();
       v = newtupleobject(4);
       if (v == NULL)
               return NULL;
       settupleitem(v, 0, newactuatorobject(a));
       settupleitem(v, 1, newactuatorobject(down_pend));
       settupleitem(v, 2, newactuatorobject(active_pend));
       settupleitem(v, 3, newactuatorobject(up_pend));
       down_pend = active_pend = up_pend = NULL;
       return v;
}

static object *
module_drawpanel(self, args)
       object *self;
       object *args;
{
       if (!getnoarg(args))
               return NULL;
       pnl_drawpanel();
       INCREF(None);
       return None;
}

static object *
module_needredraw(self, args)
       object *self;
       object *args;
{
       if (!getnoarg(args))
               return NULL;
       pnl_needredraw();
       INCREF(None);
       return None;
}

static object *
module_userredraw(self, args)
       object *self;
       object *args;
{
       short wid;
       if (!getnoarg(args))
               return NULL;
       wid = pnl_userredraw();
       return newintobject((long)wid);
}

static object *
module_block(self, args)
       object *self;
       object *args;
{
       int flag;
       if (!getintarg(args, &flag))
               return NULL;
       pnl_block = flag;
       INCREF(None);
       return None;
}

static struct methodlist module_methods[] = {
       {"block",             module_block},
       {"dopanel",           module_dopanel},
       {"drawpanel",         module_drawpanel},
       {"mkpanel",           module_mkpanel},
       {"mkact",             module_mkact},
       {"needredraw",                module_needredraw},
       {"userredraw",                module_userredraw},
       {NULL,                  NULL}           /* sentinel */
};

void
initpanel()
{
       /* Setting pnl_block to 1 would greatly reduce the CPU usage
          of an idle application.  Unfortunately it also breaks our
          little hacks to get callback functions in Python called.
          So we clear pnl_block here.  You can set/clear pnl_block
          from Python using pnl.block(flag).  It works if you have
          no upfuncs. */
       pnl_block = 0;
       initmodule("pnl", module_methods);
}
