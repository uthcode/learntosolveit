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

/* Configuration using STDWIN on the Mac (THINK_C or MPW) */

#ifdef THINK_C
#define USE_STDWIN
#endif

#ifdef USE_STDWIN
#include "stdwin.h"
#endif

void
initargs(p_argc, p_argv)
       int *p_argc;
       char ***p_argv;
{
#ifdef USE_STDWIN

#ifdef THINK_C_3_0
       wsetstdio(1);
#else
       /* This printf() statement is really needed only
          to initialize THINK C 4.0's stdio: */
       printf(
"Python 4.0, Copyright 1990 Stichting Mathematisch Centrum, Amsterdam\n");
#endif

       wargs(p_argc, p_argv);
#endif
}

void
initcalls()
{
}

void
donecalls()
{
#ifdef USE_STDWIN
       wdone();
#endif
}

#ifndef PYTHONPATH
/* On the Mac, the search path is a space-separated list of directories */
#define PYTHONPATH ": :lib :lib:stdwin :lib:mac :lib:demo"
#endif

char *
getpythonpath()
{
       return PYTHONPATH;
}


/* Table of built-in modules.
   These are initialized when first imported. */

/* Standard modules */
extern void inittime();
extern void initmath();
extern void initregexp();

/* Mac-specific modules */
extern void initmac();
#ifdef USE_STDWIN
extern void initstdwin();
#endif

struct {
       char *name;
       void (*initfunc)();
} inittab[] = {
       /* Standard modules */
       {"time",      inittime},
       {"math",      initmath},
       {"regexp",    initregexp},

       /* Mac-specific modules */
       {"mac",               initmac},
#ifdef USE_STDWIN
       {"stdwin",    initstdwin},
#endif
       {0,             0}              /* Sentinel */
};
