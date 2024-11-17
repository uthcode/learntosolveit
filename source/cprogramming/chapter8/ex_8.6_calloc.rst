==============================================
Exercise 8.6 - Write calloc, by calling malloc
==============================================

Question
========

The standard library function calloc(n,size) returns a pointer to n objects of
size size, with the storage initialized to zero. Write calloc, by calling malloc
or by modifying it.

.. literalinclude:: cprogs/ex_8.6_calloc.c
   :language: c
   :tab-width: 4

Explanation
===========

This is a custom implmentation of calloc. The standard library function calloc(n,size) returns a pointer to n objects
of `size`, with the storage intialized to zero.

This program writes calloc,by utilizing malloc.

