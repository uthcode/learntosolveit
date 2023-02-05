=====================================================
Exercise 5.13 - tail prints the last n lines of input
=====================================================

Question
========

Write the program tail, which prints the last n lines of its input.

.. literalinclude:: ../../languages/cprogs/Ex_5.13_tailn.c
   :language: c
   :tab-width: 4

   :language: c

Explanation
===========

This program is to print the last n lines of a file, with default being last 10
lines. The program sets aside an array of character pointers (strings) to store
the n  lines. The LINES value below being the maximum number of lines that can
be printed, the default value being 100.

::

    char *lineptr[LINES];   /* pointer to lines read */

The program works by first allocating enough memory for the last n lines in a
buffer. Gets each line using `mgetline(line, MAXLEN)` and then copies each line
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




.. seealso::

   * :c-suggest-improve:`Ex_5.13_tailn.c`
   * :c-better-explain:`Ex_5.13_tailn.rst`
