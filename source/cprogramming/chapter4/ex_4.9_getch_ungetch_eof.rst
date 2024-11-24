=======================================================
Exercise 4.9 - getch and ungetch handling EOF Character
=======================================================

Question
========

Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what
their properties ought to be if an EOF is pushed back, then implement your
design.

.. literalinclude:: cprogs/ex_4.9_getch_ungetch_eof.c
   :language: c

Explanation
===========

The previous `getch` and `ungetch` functions declared buf as `char buf[BUFSIZE]`.
This has a limitation wherein the when an `EOF` character is encountered, it
wont be stored in the buffer. The EOF character is an integer type. This problem
can be solved by declaring our buf to be of integer type, like `int
buf[BUFSIZE]` and `ungetch(c)` will store the character c, including EOF, now in
an integer array.

Visualize It
============

.. raw:: html

    <iframe width="100%" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0A%23define%20BUFSIZE%20100%0A%0Achar%20buf%5BBUFSIZE%5D%3B%0A%0Aint%20bufp%20%3D%200%3B%0A%0Aint%20getch%28void%29%20%7B%20return%20%28bufp%20%3E%200%29%20%3F%20buf%5B--bufp%5D%20%3A%20getchar%28%29%3B%20%7D%0A%0Avoid%20ungetch%28int%20c%29%20%7B%0A%20%20%20%20if%20%28bufp%20%3E%3D%20BUFSIZE%29%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22ungetch%3A%20too%20many%20characters%5Cn%22%29%3B%0A%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20buf%5Bbufp%2B%2B%5D%20%3D%20c%3B%0A%20%20%20%20%7D%0A%7D%0A%0Aint%20main%28int%20argc,%20char%20*argv%5B%5D%29%20%7B%0A%20%20%20%20int%20c%3B%0A%20%20%20%20c%20%3D%20'*'%3B%0A%0A%20%20%20%20while%20%28%28c%20%3D%20getch%28%29%29%20!%3D%20EOF%29%20%7B%0A%20%20%20%20%20%20%20%20putchar%28c%29%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%200%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=true&curInstr=0&heapPrimitives=false&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=true"> </iframe>


Try It
======


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex49getchungetcheof?embed=true"></iframe>
