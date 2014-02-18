==================================================================================
Exercise 4.7 - Function ungets that will push back an entire string onto the input
==================================================================================

Question
========

Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about buf and bufp, or should it just use ungetch?

.. literalinclude:: ../../languages/cprogs/Ex_4.7_ungets.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.7_ungets.c
   :language: c
   :codesite: ideone

Explaination
============



.. seealso::

   * :c-suggest-improve:`Ex_4.7_ungets.c`
   * :c-better-explain:`Ex_4.7_ungets.rst`