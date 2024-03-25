==================================================
Exercise 2.7-Setting bits at a position n Inverted
==================================================

Question
========

Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others
unchanged.

.. literalinclude:: cprogs/ex_2.7_invert.c
   :language: c

Explanation
===========

Let's take n as 3::

	~(~0 << n) = ~(~0 << 3)
 	           = ~(1111 1111 << 3)
    	       = ~(1 1111 000 << 3)
        	   = ~(1111 1000)
           	   = 0000 0111

 This sets the last n bits to 1 and rest to 0

 The given position p  0 indexed and the number of bits, n is 1 indexed.
 So in order to change the bits starting at position, p, we need to shift our
 streams 1s to position p and we accomplish that by left shifting the stream of 1s to position (p+1-n)

 For the position 3

 We get::

	~(~0 << n) << (p+1 -n)  = 0000 0111 << (3+1 -3)
					   		= 0000 0111 << 1
					   		= 000 0111 0
					   		= 0000 1111

Inverting the bits can accomplished by the XOR operation ``(^)``

So, a value like 8 which is 0000 1000 can be inverted can inverted from 3rd
position onwards by::

	x ^ (~(~0 << n) << (p + 1 - n)) = 0000 1000 ^ 0000 1111
									= 0000 1111
									= 15

Visualization
=============

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%0Aunsigned%20invert%28unsigned%20x,%20int%20p,%20int%20n%29%3B%0A%0Aint%20main%28void%29%20%7B%20printf%28%22%25u%22,%20%28unsigned%29%20invert%28%28unsigned%29%208,%20%28int%29%203,%20%28int%29%203%29%29%3B%20%7D%0A%0Aunsigned%20invert%28unsigned%20x,%20int%20p,%20int%20n%29%20%7B%0A%20%20%20%20return%20x%20%5E%20%28~%28~0%20%3C%3C%20n%29%20%3C%3C%20%28p%20%2B%201%20-%20n%29%29%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>
