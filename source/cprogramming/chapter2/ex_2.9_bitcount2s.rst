=============================================
Exercise 2.9 - two's complement number system
=============================================

Question
========

In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in
x. Explain why. Use this observation to write a faster version of bitcount.

.. literalinclude:: cprogs/ex_2.9_bitcount2s.c
   :language: c

Explanation
===========

**ones** complement is a system used in some computers to represent negative
numbers. To negate a number, each bit of the number is inverted (zeros are
replaced with ones and vice versa).

::

	...
	000...00011 = +3
	000...00010 = +2
	000...00001 = +1
	000...00000 = +0
	111...11111 = -0
	111...11110 = -1
	111...11101 = -2
	111...11100 = -3
	...

This has the consequence that there are two reperesentations for zero, either
all zeros or all ones.

In **twos complement** each bit of the number is inverted (zeros are replaced
with ones and vice versa), as for ones complement, but then one (000...0001) is
added (ignoring overflow). This avoids the two representations for zero found in
ones complement by using all ones to represent -1

::

	...
	000...00011 = +3
	000...00010 = +2
	000...00001 = +1
	000...00000 =  0
	111...11111 = -1
	111...11110 = -2
	111...11101 = -3
	...

This representation simplifies the logic required for addition and subtraction,
at the expense of a little extra complexity for negation.

For e.g

We want to calculate -4 + 5 = 1

In order to represent, -4, we can use two's complement.


::

	4 = 0000 0100
	1's complement of 4 = 1111 1011
	2's complement of 4 = 1111 1100

	5 = 0000 0101

	-4 + 5 = 1111 1100
	       + 0000 0101
	       -----------
	         0000 0001

        with 1 overflow which is ignored.

	So the answer is 0000 0001 = 1 that we expected.


The question asks us to explain why *x &= (x-1)* deletes the right most bit.

::

	x &= (x-1)  can be written as x = x & (x - 1)

	x - 1 is any binary number subtrated by 0000 0001
	x - 1 has the property of changing the right most 1 to 0.
		  and right most 0 to 1 by using borrows.


To get concrete::

	x = 1 = 0000 0001

	x-1 =   0000 0001
	      - 0000 0001
	      ------------
		0000 0000
              ------------

	x = 2 = 0000 0010

	x - 1 = 0000 0010
	       -0000 0001
	       ----------
	       	0000 0001
	       ----------

	x = 5 = 0000 0101

	x -1  = 0000 0101
	       -0000 0001
	       ----------
	        0000 0100
	       ----------

We see that x-1 has the property of inverting the last bit. So, *x & x -1* will
always set the last bit to 0.


If we use the property of **x & x-1** setting the last bit to 0, then we can  we
use this to count the number of bits. This is done in our bitcount's for loop.

::

    for(b=0; x!=0; x &= x-1)
        ++b;

This gives the number of 1 bits in our program. **AND** operation is faster than
shifting, because all bits of the number are **not** moved and thereby makes our
program more efficient.


References
==========

* `Ones complement`_
* `Twos complement`_

.. _Ones complement: http://foldoc.org/ones+complement
.. _Twos complement: http://foldoc.org/twos+complement
