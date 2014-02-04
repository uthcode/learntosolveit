=============
Exercise 1.10
=============

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

:c-suggest-improve:`Ex_1.10_TbsBlnkSpaces.c`


Explaination
------------

If the program encounters a special character like `\t` (tab) or `\b` (blank) or
`\\` (backslash), we explicitly handle that and print a `\` , using
putchar('\\') and then the literal character. For rest of the characters we
simply putchar that.

:c-better-explain:`Ex_1.10_TbsBlnkSpaces.rst`



---- 

This document was updated on |today|
