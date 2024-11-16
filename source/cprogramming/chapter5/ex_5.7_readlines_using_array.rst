====================================
Exercise 5.7 - Readlines using array
====================================

Question
========

Rewrite readlines to store lines in an array supplied by main, rather than
calling alloc to maintain storage. How much faster is the program?


.. literalinclude:: cprogs/ex_5.7_readlines_using_array.c
   :language: c
   :tab-width: 4

Explanation
===========

This uses the same qsort program. But instead of calculating the memory required
using the alloc operator. It sends a predefined amount of memory from the main
program.

It's a line sorting program written in C that reads input lines, sorts them alphabetically, and prints them out.

::

    $ ./ex_5.7_readlines_using_array
    this is a line.
    Another line.
    Good Line.
    Abacus
    Backgammon.
    ^D
    Abacus
    Another line.
    Backgammon.
    Good Line.
    this is a line.





