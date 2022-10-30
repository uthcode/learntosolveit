=============================================
Section 8.2 - Buffered and Unbuffered getchar
=============================================

Question
========

Demonstrate buffered and unbuffered getchar using the system read function.


.. literalinclude:: cprogs/sec_8.2_getchar.c
   :language: c


Explanation
===========

The un-buffered getchar, uses the system read and stores each character that is read in a character, c
and returns the character `return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;`

The buffered version of getchar, sets aside a buffer for reading the characters.

::

   static char buf[BUFSIZ];
   static char *bufp = buf;

And reads each of the characters into the buffer, `read(0, buf, sizeof buf)` and then returns one character at a
time from the buffer.

The later would be more efficient than the former one.

To execute this program, give the input in the following manner.


::

   stdin
   this is buffered getchar x
   this is unbuffered getchar x

   stdout

   this is buffered getchar
   this is unbuffered getchar

