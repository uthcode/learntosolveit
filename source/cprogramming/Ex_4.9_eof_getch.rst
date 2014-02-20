=========================================
Exercise 4.9 - push back with end of line
=========================================

Question
========

Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design.

.. literalinclude:: ../../languages/cprogs/Ex_4.9_eof_getch/.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.9_eof_getch.c
   :language: c
   :codesite: ideone

Explaination
============



.. seealso::

   * :c-suggest-improve:`Ex_4.9_eof_getch.c`
   * :c-better-explain:`Ex_4.9_eof_getch.rst`