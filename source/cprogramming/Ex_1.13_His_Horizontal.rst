=============
Exercise 1.13
=============

Question
--------


Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal.

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.13_His_Horizontal.c
   :language: c
   :tab-width: 2

.. runcode:: ../../languages/cprogs/Ex_1.13_His_Horizontal.c
   :language: c
   :codesite: ideone

:c-suggest-improve:`Ex_1.13_His_Horizontal.c`


Explaination
------------

We desire the histogram like the following.

If the input is **I love C programming**

The output should be.::

    *
    ****
    *
    ***********

The way it is accomplished in the above program, read each character using
getchar, if it is special character like a space, tab or newline,  go to next
line by printing `\n` otherwise print a `*` character.

:c-better-explain:`Ex_1.13_His_Horizontal.rst`

---- 

This document was updated on |today|
