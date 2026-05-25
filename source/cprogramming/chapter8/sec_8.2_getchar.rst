===================================
8.2 Buffered and Unbuffered getchar
===================================

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

   static char buf[BUFSIZE];
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


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20buffered%20getchar%20keeps%20a%20static%20buf%2Bptr%2Bn%3B%20drains%20without%20re-reading%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20%2F%2A%20simulate%20bgetchar%20state%3A%20static%20buffer%20filled%20once%20by%20read%28%29%20%2A%2F%0A%20%20%20%20char%20buf%5B8%5D%20%3D%20%22hi%5Cn%22%3B%0A%20%20%20%20char%20%2Abufp%20%3D%20buf%3B%0A%20%20%20%20int%20n%20%3D%203%3B%0A%20%20%20%20printf%28%22buffer%3A%20%5C%22%25s%5C%22%20%20n%3D%25d%5Cn%22%2C%20buf%2C%20n%29%3B%0A%20%20%20%20while%20%28n--%20%3E%200%29%20%7B%0A%20%20%20%20%20%20%20%20int%20c%20%3D%20%28unsigned%20char%29%2Abufp%2B%2B%3B%0A%20%20%20%20%20%20%20%20putchar%28c%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22n%3D%25d%20%28buffer%20empty%29%5Cn%22%2C%20n%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
