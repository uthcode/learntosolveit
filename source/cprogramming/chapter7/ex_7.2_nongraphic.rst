===================================================================
Exercise 7.2 - print non-graphic characters in octal or hexadecimal
===================================================================

Question
========

Write a program that will print arbitrary input in a sensible way. As a minimum,
it should print non-graphic characters in octal or hexadecimal according to
local custom, and break long text lines.

.. literalinclude:: cprogs/ex_7.2_nongraphic.c
   :language: c
   :tab-width: 4

Explanation
===========

We use the standard library function `iscntrl` declared in `ctype.h` to determine if a character is a control character.
We keep track of the position to print the output in the `inc` function and print the output in the `putchar` function.
If there is special character, we allocate 6 characters to it and print the character in octal along with the special
character.


