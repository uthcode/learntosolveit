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

/* The type of signal handlers is somewhat problematic.
   This file encapsulates my knowledge about it:
   - on the Mac (THINK C), it's int for 3.0, void for 4.0
   - on other systems, it's usually void, except it's int on vax Ultrix.
   Pass -DSIGTYPE=... to cc if you know better. */

#ifndef SIGTYPE

#ifdef THINK_C

#ifdef THINK_C_3_0
#define SIGTYPE int
#else
#define SIGTYPE void
#endif

#else /* !THINK_C */

#if defined(vax) && !defined(AMOEBA)
#define SIGTYPE int
#else
#define SIGTYPE void
#endif

#endif /* !THINK_C */

#endif /* !SIGTYPE */
