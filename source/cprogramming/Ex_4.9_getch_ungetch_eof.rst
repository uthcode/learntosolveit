=======================================================
Exercise 4.9 - getch and ungetch handling EOF Character
=======================================================

Question
========

Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design.

.. literalinclude:: ../../languages/cprogs/Ex_4.9_getch_ungetch_eof.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.9_getch_ungetch_eof.c
   :language: c
   :codesite: ideone

Explaination
============



.. seealso::

   * :c-suggest-improve:`Ex_4.9_getch_ungetch_eof.c`
   * :c-better-explain:`Ex_4.9_getch_ungetch_eof.rst`
