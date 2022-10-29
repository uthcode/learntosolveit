============================================================
Exercise 4.8 - getch and ungetch handling pushback character
============================================================

Question
========

Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly.


.. literalinclude:: cprogs/ex_4.8_getch_ungetch_pushback.c
   :language: c

Explanation
===========

This program maintains a character buffer `char buf=0` which holds a single
character from the input. The function `ungetch(c)` when called places the
character in the input and `getch()`, if it finds the character in the buf,
returns it or it calls `getchar` to get character from the user.

