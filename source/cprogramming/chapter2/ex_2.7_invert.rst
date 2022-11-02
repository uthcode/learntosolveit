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
