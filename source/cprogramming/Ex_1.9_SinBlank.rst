============
Exercise 1.9
============

Question
--------


Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.9_SinBlank.c
   :language: c
   :tab-width: 2

.. runcode:: ../../languages/cprogs/Ex_1.9_SinBlank.c
   :language: c
   :codesite: ideone

:c-suggest-improve:`Ex_1.9_SinBlank.c`


Explaination
------------

The essence of this program is, while reading the characters, if the last
character that we encoutered is a blank, then we skip printing it.

::

	if(lastc!=' ')
        putchar(c);

This means that if the last character is not a blank, *only* then print it.
We store the last character in the lastc variable in the line `lastc = c`.
For rest of the characters we simplying print it by `putchar (c)`.

:c-better-explain:`Ex_1.9_SinBlank.rst`



---- 

This document was updated on |today|
