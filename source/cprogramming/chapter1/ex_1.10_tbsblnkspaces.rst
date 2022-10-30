=======================================================
Exercise 1.10 - Explicit Tabs, Backslash and Backspaces
=======================================================

Question
--------

Write a Program to copy its input to its output, replacing each tab by \t,each
backspace by \b, and each backslash by \\. This makes tabs and backspaces
visible in an unambiguous way.

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.10_TbsBlnkSpaces.c
   :language: c
   :tab-width: 2

.. runcode:: ../../languages/cprogs/Ex_1.10_TbsBlnkSpaces.c
   :language: c
   :codesite: ideone

:use-local-compiler:`gcc`

Explanation
===========

If the program encounters a special character like ``\t`` (tab) or ``\b`` (blank) or
``\\`` (backslash), we explicitly handle that and print a ``\`` , using
putchar('\\') and then the literal character. For rest of the characters we
simply putchar that.

.. seealso::

   * :c-suggest-improve:`Ex_1.10_TbsBlnkSpaces.c`
   * :c-better-explain:`Ex_1.10_TbsBlnkSpaces.rst`

