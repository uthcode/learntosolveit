================================================
Exercise 2.10 - upper case letters to lower case
================================================

Question
========

Rewrite the function lower, which converts upper case letters to lower case, with a
conditional expression instead of if-else.

.. literalinclude:: ../../languages/cprogs/Ex_2.10_lowercondit.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_2.10_lowercondit.c
   :language: c
   :codesite: ideone

Explaination
============

In this program we are going to convert upper case letters to lower case.
We do this by
<<<<<<< HEAD:source/cprogramming/lower.rst
:: 
   while((c=getchar())!=EOF)
	  {
	  	putchar(lower(c));
	  }
=======
::

   while((c=getchar()) != EOF)
   putchar(tolower(c));

>>>>>>> c4f5eaee07f20f3cdcede70817402b2b4110029f:source/cprogramming/Ex_2.10_lower.rst
Which means that when we enter a applet the program checks for the end of file and if the letters are in the upper case we convert them into lower case.


.. seealso::

<<<<<<< HEAD:source/cprogramming/lower.rst
   * :c-suggest-improve:`Ex_2.10_lowercondit.c`
   * :c-better-explain:`Ex_2.10_lowercondit.rst`
=======
   * :c-suggest-improve:`Ex_2.10_lower.c`
   * :c-better-explain:`Ex_2.10_lower.rst`
>>>>>>> c4f5eaee07f20f3cdcede70817402b2b4110029f:source/cprogramming/Ex_2.10_lower.rst
