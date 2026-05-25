=====================================
2.10 upper case letters to lower case
=====================================

Question
========

Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else.

.. coderun:: cprogs/ex_2.10_lowercondit.c
   :language: c

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

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20conditional%20expression%20to%20convert%20uppercase%20to%20lowercase%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20lower%28int%20c%29%20%7B%20return%20c%20%3E%3D%20%27A%27%20%26%26%20c%20%3C%3D%20%27Z%27%20%3F%20c%20%2B%20%27a%27%20-%20%27A%27%20%3A%20c%3B%20%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22Hi%22%3B%0A%20%20%20%20int%20i%20%3D%200%3B%0A%20%20%20%20while%20%28s%5Bi%5D%29%20%7B%20putchar%28lower%28s%5Bi%5D%29%29%3B%20i%2B%2B%3B%20%7D%0A%20%20%20%20putchar%28%27%5Cn%27%29%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
