==================================================================================
Exercise 4.7 - Function ungets that will push back an entire string onto the input
==================================================================================

Question
========

Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?

.. literalinclude:: cprogs/ex_4.7_ungets.c
   :language: c

Explanation
===========

This program defines `ungets(s)`, which takes a string as an input and and
removes one character at a time from the back of the string and puts them into a
the buffer BUF. It does this, till all the characters from the input string are
placed onto the buffer. It uses the function `ungetch` to place to the buffer.

When getch() is called, the characters from the buffer are read first and it is
output on the screen.

So, when we write something like this.

::

    $ ./a.out
    this is a sentence
    this is a sentence

The first sentence is read as input and placed in the BUF and the next sentence
is read using `getch()` from the BUF array.
