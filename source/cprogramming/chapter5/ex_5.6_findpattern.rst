===================================
5.6 Find the pattern using pointers
===================================

Question
========

Rewrite appropriate programs from earlier chapters and exercises with pointers
instead of array indexing. Good possibilities include getline (Chapters 1 and
4), atoi, itoa, and their variants (Chapters 2, 3, and 4), reverse (Chapter 3),
and strindex and getop (Chapter 4).

.. literalinclude:: cprogs/ex_5.6_findpattern.c
   :language: c
   :tab-width: 4

Explanation
===========

_getline takes a string ``(char *)`` and MAXLINE, the maximum length of the line. It
gets one character at a time using getchar() and as long as we are under limit
(less than MAXLINE) and it is not \n character. It stores the charaacters in the
line, advancing the pointer for each character.

When it hits \n, it adds \n and closes the line with \0. _getline returns the
length of the line, subtracting the last address with initial address.


atoi - the gets the sign and then read each read each character using the
pointer, checks if it is digit and converts it to integer. The curx of this
function is::

   for(n=0;isdigit(*s);s++)
           n = 10 *n + *s - '0';

itoa - takes the number, converts it into a string, by adding '0' and stores
them to a character pointer, advancing the pointer after each assignment. When
the assignments are done, it adds a null character to form a valid C string::

    do
    {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);

    if(sign < 0)
        *s++ = '-';
    *s='\0';


reverse takes a ``char *s`` as argument and uses a temporary string ``char *t``, to
swap the characters from the end to the front. It uses another intermediate
character ``c`` to do the swap.

strindex takes two strings ``char *s`` and ``char *t`` and determines the start of
the string t in s. It stores the s position in the base, b and then advances s
and for each advance checks if the substring t is contained in s. If the
substring is contained, it returns the current position - base position, that ``s
-b``, otherwise it returns -1.

getop works by taking a ``char *s`` as it's argument. It reads the character and
stores it in s. It skips the whitespaces and then checks if it isdigit.
If it not a digit, it closes the string using \0 and returns the character.

If it is digit, then it reads both real and decimal part, along with dot, closes
the string using \0 and the returns that it found a NUMBER. 

Since checking of the character, happens after reading, an extra character is
read when our condition fails (that is we have completely read the NUMBER) In
that case, we do a ungetch, to return the character back to buffer and return
that we found a NUMBER.






Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20strindex%20scans%20s%20for%20first%20match%20of%20pattern%20t%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20strindex%28char%20s%5B%5D%2C%20char%20t%5B%5D%29%20%7B%0A%20%20%20%20int%20i%2C%20j%2C%20k%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20s%5Bi%5D%20%21%3D%20%27%5C0%27%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20for%20%28j%3Di%2C%20k%3D0%3B%20t%5Bk%5D%21%3D%27%5C0%27%20%26%26%20s%5Bj%5D%3D%3Dt%5Bk%5D%3B%20j%2B%2B%2C%20k%2B%2B%29%3B%0A%20%20%20%20%20%20%20%20if%20%28k%20%3E%200%20%26%26%20t%5Bk%5D%20%3D%3D%20%27%5C0%27%29%20return%20i%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20-1%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20strindex%28%22hello%22%2C%20%22ell%22%29%29%3B%20%2F%2A%201%20%2A%2F%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20strindex%28%22hello%22%2C%20%22xyz%22%29%29%3B%20%2F%2A%20-1%20%2A%2F%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
