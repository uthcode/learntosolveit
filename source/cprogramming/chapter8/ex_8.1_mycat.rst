=================================================
8.1 program cat using read, write, open and close
=================================================

Question
========

Rewrite the program cat from Chapter 7 using read, write, open, and close
instead of their standard library equivalents. Perform experiments to determine
the relative speeds of the two versions.

.. literalinclude:: cprogs/ex_8.1_mycat.c
   :language: c


Explanation
===========

This is custom implementation of `cat` program using read/write/open/close function calls instead of the standard library ones.




Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20read%28%29%20fills%20a%20buffer%3B%20write%28%29%20drains%20it%20%E2%80%94%20the%20copy%20loop%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20src%5B%5D%20%3D%20%22hello%5Cn%22%3B%0A%20%20%20%20char%20buf%5B8%5D%3B%0A%20%20%20%20int%20i%2C%20n%20%3D%206%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20n%3B%20i%2B%2B%29%20buf%5Bi%5D%20%3D%20src%5Bi%5D%3B%0A%20%20%20%20buf%5Bn%5D%20%3D%20%27%5C0%27%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20n%3B%20i%2B%2B%29%20putchar%28buf%5Bi%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
