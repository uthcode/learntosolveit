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
We declare a variable called lower in the beginning of the program.
When the program enters the while loop it checks for the condition::

	while((c=getchar())!=EOF)
    	{
        	putchar(lower(c));
    	}

The getchar checks for all the uppercase characters up to the end of file.
This is done by the return statement where it checks for all the uppercase characters and prints everything in the lowercase::

  return c>='A' && c<='Z'? c+'a'-'A':c;    	


.. seealso::

   * :c-suggest-improve:`Ex_2.10_lowercondit.c`
   * :c-better-explain:`Ex_2.10_lowercondit.rst`