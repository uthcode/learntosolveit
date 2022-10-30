===========================================================
Exercise 1.9 - Replace Continous blanks with a single blank
===========================================================

Question
--------


Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.

Solution
--------

.. literalinclude:: cprogs/ex_1.9_sinblank.c
   :language: c

Explanation
===========

The essence of this program is, while reading the characters, if the last
character that we encoutered is a blank, then we skip printing it.

::

    if(lastc!=' ')
        putchar(c);

This means that if the last character is not a blank, *only* then print it. We
store the last character in the lastc variable in the line `lastc = c`. For rest
of the characters we simplying print it by `putchar (c)`.

