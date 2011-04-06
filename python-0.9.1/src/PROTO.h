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

/*
The macro PROTO(x) is used to put function prototypes in the source.
This is defined differently for compilers that support prototypes than
for compilers that don't.  It should be used as follows:
       int some_function PROTO((int arg1, char *arg2));
A variant FPROTO(x) is used for cases where Standard C allows prototypes
but Think C doesn't (mostly function pointers).

This file also defines the macro HAVE_PROTOTYPES if and only if
the PROTO() macro expands the prototype.  It is also allowed to predefine
HAVE_PROTOTYPES to force prototypes on.
*/

#ifndef PROTO

#ifdef __STDC__
#define HAVE_PROTOTYPES
#endif

#ifdef THINK_C
#undef HAVE_PROTOTYPES
#define HAVE_PROTOTYPES
#endif

#ifdef sgi
#ifdef mips
#define HAVE_PROTOTYPES
#endif
#endif

#ifdef HAVE_PROTOTYPES
#define PROTO(x) x
#else
#define PROTO(x) ()
#endif

#endif /* PROTO */


/* FPROTO() is for cases where Think C doesn't like prototypes */

#ifdef THINK_C
#define FPROTO(arglist) ()
#else /* !THINK_C */
#define FPROTO(arglist) PROTO(arglist)
#endif /* !THINK_C */

#ifndef HAVE_PROTOTYPES
#define const /*empty*/
#else /* HAVE_PROTOTYPES */
#ifdef THINK_C
#undef const
#define const /*empty*/
#endif /* THINK_C */
#endif /* HAVE_PROTOTYPES */
