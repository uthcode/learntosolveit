============================================================
Exercise 4.8 - getch and ungetch handling pushback character
============================================================

Question
========

Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly


.. literalinclude:: ../../languages/cprogs/Ex_4.8_getch_ungetch_pushback.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.8_getch_ungetch_pushback.c
   :language: c
   :codesite: ideone

Explaination
============

This program maintains a character buffer `char buf=0` which holds a single
character from the input. The function `ungetch(c)` when called places the
character in the input and `getch()`, if it finds the character in the buf,
returns it or it calls `getchar` to get character from the user.


.. seealso::

   * :c-suggest-improve:`Ex_4.8_getch_ungetch_pushback.c`
   * :c-better-explain:`Ex_4.8_getch_ungetch_pushback.rst`