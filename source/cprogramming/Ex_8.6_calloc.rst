==============================================
Exercise 8.6 - Write calloc, by calling malloc
==============================================

Question
========

The standard library function calloc(n,size) returns a pointer to n objects of
size size, with the storage initialized to zero. Write calloc, by calling malloc
or by modifying it.

.. literalinclude:: ../../languages/cprogs/Ex_8.6_calloc.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_8.6_calloc.c
   :language: c
   :codesite: ideone

Explanation
===========

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_8.6_calloc.c`
   * :c-better-explain:`Ex_8.6_calloc.rst`
