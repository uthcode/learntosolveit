=========================================================
Exercise 1.16 - Print length of arbitrary long input line
=========================================================

Question
--------


Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text.

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.16_LongLine.c
   :language: c
   :tab-width: 4


.. runcode:: ../../languages/cprogs/Ex_1.16_LongLine.c
   :language: c
   :codesite: ideone

Explanation
===========

A string in C is a character array which ends in `\0`. getline is a function in
our program, which reads one character at a time using getchar and stores it in
a character array called s[] and it returns the length of the array.

We keep track of each line and it's length using a variable, `max`. If the
length of the line is greater than `max`, then we copy that line into the
`maxline` using a copy routine.

At the end of the program, whichever was the longest line that was copied in
maxline array, we just print that.



.. seealso::

   * :c-suggest-improve:`Ex_1.16_LongLine.c`
   * :c-better-explain:`Ex_1.16_LongLine.rst`

