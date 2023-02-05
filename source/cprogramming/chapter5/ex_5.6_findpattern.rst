==============================================
Exercise 5.6 - Find the pattern using pointers
==============================================

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

mgetline takes a string ``(char *)`` and MAXLINE, the maximum length of the line. It
gets one character at a time using getchar() and as long as we are under limit
(less than MAXLINE) and it is not \n character. It stores the charaacters in the
line, advancing the pointer for each character.

When it hits \n, it adds \n and closes the line with \0. mgetline returns the
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





