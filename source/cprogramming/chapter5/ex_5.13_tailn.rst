==========================================
5.13 tail prints the last n lines of input
==========================================

Question
========

Write the program tail, which prints the last n lines of its input.

.. coderun:: cprogs/ex_5.13_tailn.c
   :language: c
   :tab-width: 4


Explanation
===========

This program is to print the last n lines of a file, with default being last 10
lines. The program sets aside an array of character pointers (strings) to store
the n  lines. The LINES value below being the maximum number of lines that can
be printed, the default value being 100.

::

    char *lineptr[LINES];   /* pointer to lines read */

The program works by first allocating enough memory for the last n lines in a
buffer. Gets each line using `_getline(line, MAXLEN)` and then copies each line
to an index entry in the lineptr array.

::

	strcpy(lineptr[last],line);

It advances the pointer `last` at each copy, and when it exceed the maximum
count, it just rolls over, starting from 0.

Next, we have to define the logic to print the last n lines. We offset line
value appropriately to the number of lines. It is either `last - n` lines and if
that value goes negative, then we increment it to max lines LINES. We start at
first value of line and as long as the the line number count represented by n
exists, we print the line, decrementing the count at each step.






Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20circular%20buffer%20to%20keep%20last%20N%20lines%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0A%23define%20TAIL%202%0A%23define%20MAXLEN%2010%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20lines%5BTAIL%5D%5BMAXLEN%5D%3B%0A%20%20%20%20char%20%2Adata%5B%5D%20%3D%20%7B%22line1%22%2C%20%22line2%22%2C%20%22line3%22%7D%3B%0A%20%20%20%20int%20n%20%3D%203%2C%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20n%3B%20i%2B%2B%29%20strcpy%28lines%5Bi%20%25%20TAIL%5D%2C%20data%5Bi%5D%29%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20TAIL%3B%20i%2B%2B%29%20printf%28%22%25s%5Cn%22%2C%20lines%5B%28n%20%2B%20i%29%20%25%20TAIL%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
