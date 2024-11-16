===========================================
Exercise 2.6 - Setting bits at a position n
===========================================

Question
========

Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.

.. literalinclude:: cprogs/ex_2.6_setbits.c
   :language: c

Explanation
===========

The setbits function takes 4 inputs:

- x: The original number we want to modify
- p: The position where we want to make changes (counting from right, starting at 0)
- n: How many bits we want to replace
- y: The number we want to take bits from


The function replaces n bits in x, starting at position p, with the rightmost n bits from y.

::

    setbits(0x37, 3, 2, 0x4E)  // Returns 0x3B

 - x = 0x37 = 0011 0111 in binary
 - Starting at position 3 (p=3)
 - We want to change 2 bits (n=2)
 - Taking (2 ) bits from y = 0x4E = 0100 1110

 The function:

 - Takes the rightmost 2 bits from y (10)
 - Places them at position 3 in x

 ::

     Original: 0011 0111
     Result:   0011 1011 (0x3B)

Visualization
=============

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%0Aunsigned%20setbits%28unsigned%20x,%20int%20p,%20int%20n,%20unsigned%20y%29%3B%0A%0Aint%20main%28void%29%20%7B%20printf%28%22%25u%22,%20setbits%28%28unsigned%2912,%203,%202,%20%28unsigned%2957%29%29%3B%20%7D%0A%0Aunsigned%20setbits%28unsigned%20x,%20int%20p,%20int%20n,%20unsigned%20y%29%20%7B%0A%20%20%20%20return%20%28x%20%26%20~%28~%28~0%20%3C%3C%20n%29%20%3C%3C%20%28p%20%2B%201%20-%20n%29%29%29%20%7C%0A%20%20%20%20%20%20%20%20%20%20%20%28y%20%26%20%28~%28~0%20%3C%3C%20n%29%29%20%3C%3C%20%28p%20%2B%201%20-%20n%29%29%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>

