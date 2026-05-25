===================================
1.8 Count blanks, tabs and newlines
===================================

Question
--------

Write a program to count blanks, tabs, and newlines.

Solution
--------

.. literalinclude:: cprogs/ex_1.8_count_blanks_etc.c
   :language: c

Explanation
===========

In this program we are going to count the number of Blanks, tabs and new lines
present in the input.  To do this the program, while reading the characters
checks for the condition c = getchar !=EOF which means if the character is not
end of file continue counting Blanks tabs and newlines. Example input:

I like programming
In C
And the out put shall be:
Blanks: 4
Tabs: 0
Newlines: 1


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20count%20blanks%2C%20tabs%2C%20newlines%20using%20separate%20int%20counters%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22a%20%5Ctb%5Cn%22%3B%0A%20%20%20%20int%20nb%20%3D%200%2C%20nt%20%3D%200%2C%20nl%20%3D%200%2C%20i%20%3D%200%2C%20c%3B%0A%20%20%20%20while%20%28%28c%20%3D%20%28unsigned%20char%29s%5Bi%2B%2B%5D%29%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%20%27%29%20%20%2B%2Bnb%3B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%5Ct%27%29%20%2B%2Bnt%3B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%5Cn%27%29%20%2B%2Bnl%3B%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22blanks%3D%25d%20tabs%3D%25d%20newlines%3D%25d%5Cn%22%2C%20nb%2C%20nt%2C%20nl%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
