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




