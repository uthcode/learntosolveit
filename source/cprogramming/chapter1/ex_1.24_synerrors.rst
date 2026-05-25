===================================================
1.24 Check rudimentary Syntax Errors in a C Program
===================================================

Question
--------


Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses,brackets and braces. Don't forget about quotes, both
single and double, escape sequences, and comments. (This program is hard if you
do it in full generality.)


Solution
--------

.. coderun:: cprogs/ex_1.24_synerrors.c
   :language: c

Explanation
===========

We divide the program up into 3 parts. The text of the program when it is in-
comment, in-quote and rest of the program text. We don't to have worry about the
part when we are in-comment or in-quote because we can find non-matching
brankets or braces in those parts. It is only the rest that we care about.

When a two sequence characters starts with  ``/*`` we enter in-comment block and
continue till we end up with ``*/``

When a single quote ``'`` or a double quote ``"`` character is found, we do the same
and continue till we find it's match.

For the rest of the program, when we first match a brace, bracket or
parenthesis, we mark it as -1 and when we find it's match, we negate it back to
0. If these values end up being anythign other than 0, we say that we found a
mismatch.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20count%20braces%20and%20parentheses%20to%20check%20balance%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22if%20%28x%29%20%7B%20y%3B%20%7D%22%3B%0A%20%20%20%20int%20brace%20%3D%200%2C%20paren%20%3D%200%2C%20i%20%3D%200%2C%20c%3B%0A%20%20%20%20while%20%28%28c%20%3D%20%28int%29%28unsigned%20char%29s%5Bi%2B%2B%5D%29%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%7B%27%29%20%2B%2Bbrace%3B%0A%20%20%20%20%20%20%20%20else%20if%20%28c%20%3D%3D%20%27%7D%27%29%20--brace%3B%0A%20%20%20%20%20%20%20%20else%20if%20%28c%20%3D%3D%20%27%28%27%29%20%2B%2Bparen%3B%0A%20%20%20%20%20%20%20%20else%20if%20%28c%20%3D%3D%20%27%29%27%29%20--paren%3B%0A%20%20%20%20%7D%0A%20%20%20%20if%20%28brace%20%21%3D%200%29%20printf%28%22Unmatched%20braces%5Cn%22%29%3B%0A%20%20%20%20else%20if%20%28paren%20%21%3D%200%29%20printf%28%22Unmatched%20parenthesis%5Cn%22%29%3B%0A%20%20%20%20else%20printf%28%22Balanced%5Cn%22%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
