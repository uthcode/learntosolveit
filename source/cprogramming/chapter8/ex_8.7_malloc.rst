=======================================
Exercise 8.7 - Error checking by malloc
=======================================

Question
========

Malloc accepts a size request without checking its plausibility; free believes
that the block it is asked to free contains a valid size field. Improve these
routines so they make more pains with error checking.

.. literalinclude:: cprogs/ex_8.7_malloc.c
   :language: c

Explanation
===========

