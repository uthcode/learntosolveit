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

.. literalinclude:: cprogs/ex_1.10_tbsblnkspaces.c
   :language: c

Explanation
===========

If the program encounters a special character like ``\t`` (tab) or ``\b`` (blank) or
``\\`` (backslash), we explicitly handle that and print a ``\`` , using
putchar('\\') and then the literal character. For rest of the characters we
simply putchar that.
