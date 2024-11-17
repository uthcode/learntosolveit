===========================================
Exercise 8.3 - _flushbuf, fflush and fclose
===========================================

Question
========

Design and write _flushbuf, fflush, and fclose.

**inprogress**

.. literalinclude:: cprogs/ex_8.3.c
   :language: c

Explanation
===========

This is an internal implementation of `_flushbuf`, `fflush`, and `fclose`. This is implemented by defining a structure called
`_iobuf`, making it point to a file pointer, and reading the contents as a linked list implementation, each time allocating a memory to `base` in the iobuf.

