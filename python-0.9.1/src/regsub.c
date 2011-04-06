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
 * regsub
 *
 *     Copyright (c) 1986 by University of Toronto.
 *     Written by Henry Spencer.  Not derived from licensed software.
#ifdef MULTILINE
 *     Changed by Guido van Rossum, CWI, Amsterdam
 *     for multi-line support.
#endif
 *
 *     Permission is granted to anyone to use this software for any
 *     purpose on any computer system, and to redistribute it freely,
 *     subject to the following restrictions:
 *
 *     1. The author is not responsible for the consequences of use of
 *             this software, no matter how awful, even if they arise
 *             from defects in it.
 *
 *     2. The origin of this software must not be misrepresented, either
 *             by explicit claim or by omission.
 *
 *     3. Altered versions must be plainly marked as such, and must not
 *             be misrepresented as being the original software.
 */
#include <stdio.h>
#include "regexp.h"
#include "regmagic.h"

#ifndef CHARBITS
#define        UCHARAT(p)      ((int)*(unsigned char *)(p))
#else
#define        UCHARAT(p)      ((int)*(p)&CHARBITS)
#endif

/*
 - regsub - perform substitutions after a regexp match
 */
void
regsub(prog, source, dest)
regexp *prog;
char *source;
char *dest;
{
       register char *src;
       register char *dst;
       register char c;
       register int no;
       register int len;
       extern char *strncpy();

       if (prog == NULL || source == NULL || dest == NULL) {
               regerror("NULL parm to regsub");
               return;
       }
       if (UCHARAT(prog->program) != MAGIC) {
               regerror("damaged regexp fed to regsub");
               return;
       }

       src = source;
       dst = dest;
       while ((c = *src++) != '\0') {
               if (c == '&')
                       no = 0;
               else if (c == '\\' && '0' <= *src && *src <= '9')
                       no = *src++ - '0';
               else
                       no = -1;

               if (no < 0) {        /* Ordinary character. */
                       if (c == '\\' && (*src == '\\' || *src == '&'))
                               c = *src++;
#ifdef MULTILINE
                       else if (c == '\\' && *src == 'n') {
                               c = '\n';
                               src++;
                       }
#endif
                       *dst++ = c;
               } else if (prog->startp[no] != NULL && prog->endp[no] != NULL) {
                       len = prog->endp[no] - prog->startp[no];
                       (void) strncpy(dst, prog->startp[no], len);
                       dst += len;
                       if (len != 0 && *(dst-1) == '\0') {     /* strncpy hit NUL. */
                               regerror("damaged match string");
                               return;
                       }
               }
       }
       *dst++ = '\0';
}
