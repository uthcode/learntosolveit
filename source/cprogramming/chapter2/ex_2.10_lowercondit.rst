================================================
Exercise 2.10 - upper case letters to lower case
================================================

Question
========

Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else.

.. literalinclude:: ../../languages/cprogs/Ex_2.10_lowercondit.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_2.10_lowercondit.c
   :language: c
   :codesite: ideone

Explanation
===========

In this program we are going to convert upper case letters to lower case. We
declare a function called lower in the beginning of the program. When the
program enters the while loop it each character it gets to lower::

	while((c=getchar())!=EOF)
    	{
        	putchar(lower(c));
    	}

The lower function checks for all the uppercase characters and prints everything
in the lowercase. It does this by a conditional statement, where if a upper case
character is found, it subtracts 'A' to get relative index, adds it to 'a' to
return corresponding smaller case character, if a lower case character is found,
it is simply returned::

  return c>='A' && c<='Z'? c+'a'-'A':c;    	



.. seealso::

   * :c-suggest-improve:`Ex_2.10_lowercondit.c`
   * :c-better-explain:`Ex_2.10_lowercondit.rst`
