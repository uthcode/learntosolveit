=======================================================
Exercise 4.9 - getch and ungetch handling EOF Character
=======================================================

Question
========

Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what
their properties ought to be if an EOF is pushed back, then implement your
design.

.. literalinclude:: ../../languages/cprogs/Ex_4.9_getch_ungetch_eof.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.9_getch_ungetch_eof.c
   :language: c
   :codesite: ideone

Explanation
===========

The previous `getch` and `ungetch` functions declared buf as `char buf[BUFSIZ]`.
This has a limitation wherein the when an `EOF` character is encountered, it
wont be stored in the buffer. The EOF character is an integer type. This problem
can be solved by declaring our buf to be of integer type, like `int
buf[BUFSIZE]` and `ungetch(c)` will store the character c, including EOF, now in
an integer array.

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_4.9_getch_ungetch_eof.c`
   * :c-better-explain:`Ex_4.9_getch_ungetch_eof.rst`
