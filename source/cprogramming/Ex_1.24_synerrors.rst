=============
Exercise 1.24
=============

Question
--------


Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses,brackets and braces. Don't forget about quotes, both
single and double, escape sequences, and comments. (This program is hard if you
do it in full generality.)


Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.24_synerrors.c
   :language: c
   :tab-width: 4


.. runcode:: ../../languages/cprogs/Ex_1.24_synerrors.c
   :language: c
   :codesite: ideone



:c-suggest-improve:`Ex_1.24_synerrors.c`

Explaination
------------

We divide the program up into 3 parts. The text of the program when it is in-
comment, in-quote and rest of the program text. We don't to have worry about the
part when we are in-comment or in-quote because we can find non-matching
brankets or braces in those parts. It is only the rest that we care about.

When a two sequence characters starts with  `/*` we enter in-comment block and
continue till we end up with '*/'

When a single quote `'` or a double quote `"` character is found, we do the same
and continue till we find it's match.

For the rest of the program, when we first match a brace, bracket or
parenthesis, we mark it as -1 and when we find it's match, we negate it back to
0. If these values end up being anythign other than 0, we say that we found a
mismatch.

:c-better-explain:`Ex_1.24_synerrors.rst`


---- 

This document was updated on |today|
