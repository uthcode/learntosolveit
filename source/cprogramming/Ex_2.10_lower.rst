================================================
Exercise 2.10 - upper case letters to lower case
================================================

Question
========

Rewrite the function lower, which converts upper case letters to lower case, with a
conditional expression instead of if-else.

.. literalinclude:: ../../languages/cprogs/Ex_2.10_lower.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_2.10_lower.c
   :language: c
   :codesite: ideone

Explaination
============

In this program we are going to convert upper case letters to lower case.
We do this by
::

   while((c=getchar()) != EOF)
   putchar(tolower(c));

Which means that when we enter a applet the program checks for the end of file and if the letters are in the upper case we convert them into lower case.


.. seealso::

   * :c-suggest-improve:`Ex_2.10_lower.c`
   * :c-better-explain:`Ex_2.10_lower.rst`
