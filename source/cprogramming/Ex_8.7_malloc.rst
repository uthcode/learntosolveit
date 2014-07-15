=======================================
Exercise 8.7 - Error checking by malloc
=======================================

Question
========

Malloc accepts a size request without checking its plausibility; free believes
that the block it is asked to free contains a valid size field. Improve these
routines so they make more pains with error checking.

.. literalinclude:: ../../languages/cprogs/Ex_8.7_malloc.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_8.7_malloc.c
   :language: c
   :codesite: ideone

Explaination
============

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_8.7_malloc.c`
   * :c-better-explain:`Ex_8.7_malloc.rst`