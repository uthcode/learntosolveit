==============================
Exercise 8.4 - implement fseek
==============================

Question
========

The standard library function:

	``int fseek(FILE *fp, long offset, int origin)``

**inprogress**


.. literalinclude:: cprogs/ex_8.4.c
   :language: c
   :tab-width: 4

Explanation
===========

This uses three fields

::

    #define SEEK_SET 0
    #define SEEK_CUR 1
    #define SEEK_END 2

and determines where we are in the file using the file seek operations.

