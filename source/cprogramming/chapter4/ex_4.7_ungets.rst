==================================================================================
Exercise 4.7 - Function ungets that will push back an entire string onto the input
==================================================================================

Question
========

Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?

.. literalinclude:: cprogs/ex_4.7_ungets.c
   :language: c

Explanation
===========

This program defines `ungets(s)`, which takes a string as an input and and
removes one character at a time from the back of the string and puts them into a
the buffer BUF. It does this, till all the characters from the input string are
placed onto the buffer. It uses the function `ungetch` to place to the buffer.

When getch() is called, the characters from the buffer are read first and it is
output on the screen.

So, when we write something like this.

::

    $ ./a.out
    this is a sentence
    this is a sentence

The first sentence is read as input and placed in the BUF and the next sentence
is read using `getch()` from the BUF array.

Visualize It
============

.. raw:: html

   <iframe width="100%" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0A%0A%23define%20BUFSIZE%20100%0A%23define%20MAXLINE%201000%0A%0Achar%20buf%5BBUFSIZE%5D%3B%0Aint%20bufp%20%3D%200%3B%0A%0Aint%20getch%28void%29%3B%0Avoid%20ungetch%28int%29%3B%0Avoid%20ungets%28char%20s%5B%5D%29%3B%0Aint%20mgetline%28char%20s%5B%5D,%20int%20lim%29%3B%0A%0Aint%20main%28int%20argc,%20char%20*argv%5B%5D%29%20%7B%0A%20%20%20%20char%20line%5BMAXLINE%5D%3B%0A%20%20%20%20int%20len%3B%0A%0A%20%20%20%20while%20%28%28len%20%3D%20mgetline%28line,%20MAXLINE%29%29%20%3E%200%29%20%7B%0A%20%20%20%20%20%20%20%20ungets%28line%29%3B%0A%20%20%20%20%20%20%20%20while%20%28%28len%20%3D%20mgetline%28line,%20MAXLINE%29%29%20%3E%200%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22%25s%22,%20line%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A%0Aint%20mgetline%28char%20s%5B%5D,%20int%20lim%29%20%7B%0A%20%20%20%20int%20c,%20i%3B%0A%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20lim%20-%201%20%26%26%20%28c%20%3D%20getchar%28%29%29%20!%3D%20EOF%20%26%26%20c%20!%3D%20'%5Cn'%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20%20%20%20%20s%5Bi%5D%20%3D%20c%3B%0A%20%20%20%20%7D%0A%20%20%20%20if%20%28c%20%3D%3D%20'%5Cn'%29%20%7B%0A%20%20%20%20%20%20%20%20s%5Bi%5D%20%3D%20c%3B%0A%20%20%20%20%20%20%20%20%2B%2Bi%3B%0A%20%20%20%20%7D%0A%20%20%20%20s%5Bi%5D%20%3D%20'%5C0'%3B%0A%20%20%20%20return%20i%3B%0A%7D%0A%0Aint%20getch%28void%29%20%7B%20return%20%28bufp%20%3E%200%29%20%3F%20buf%5B--bufp%5D%20%3A%20getchar%28%29%3B%20%7D%0A%0Avoid%20ungetch%28int%20c%29%20%7B%0A%20%20%20%20if%20%28bufp%20%3E%3D%20BUFSIZE%29%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22ungetch%3A%20too%20many%20characters%5Cn%22%29%3B%0A%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20buf%5Bbufp%2B%2B%5D%20%3D%20c%3B%0A%20%20%20%20%7D%0A%7D%0A%0Avoid%20ungets%28char%20s%5B%5D%29%20%7B%0A%20%20%20%20int%20len%20%3D%20strlen%28s%29%3B%0A%20%20%20%20while%20%28len%20%3E%200%29%20%7B%0A%20%20%20%20%20%20%20%20ungetch%28s%5B--len%5D%29%3B%0A%20%20%20%20%7D%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=true&curInstr=0&heapPrimitives=false&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=true"> </iframe>


Try It
======


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex47ungets?embed=true"></iframe>
