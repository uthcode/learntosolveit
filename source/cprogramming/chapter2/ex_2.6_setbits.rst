===========================================
Exercise 2.6 - Setting bits at a position n
===========================================

Question
========

Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.

.. literalinclude:: ../../languages/cprogs/Ex_2.6_setbits.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_2.6_setbits.c
   :language: c
   :codesite: ideone

Explanation
===========

The important piece of the program is this::

	(x & ~(~(~0 << n) << (p+1-n))) | ( y & (~(~0<<n) << (p+1-n)));

Let's look at some inner terms. The expression `~(~0<<n)` will thus always yield
right most n bits set to 1. And (p+1-n) will give a integer  value for the n
digits at position p we want. We do p+1 because our position is 0 indexed while
count of digits n is 1 indexed. For e.g. in a number `1111 1111`, the **4**
digits starting the position **3** is **1111**

Let's refactor the program to understandable portions. 

RIGHT_MOST_N_1S = ~(~0 << n)
GET_N_DIGITS = (p + 1 -n)

The above expression becomes::

	(x & ~(RIGHT_MOST_N_1S << GET_N_DIGITS)) | (( y & RIGHT_MOST_N_1S) << GET_N_DIGITS);

For a moment, let's take the word that left shifting operation will give us
expected bits. For e.g: 0000 1111 << 4 will give us 1111 0000

Reducing it further, it becomes::

	(x & ~(Expected bits marked as 1) | ((Right most bits in y) << GET_N_DIGITS);

	(x & (Expected bits marked as 0) | (Expected bits marked as 1 in y and rest as 0);

So in x we switch off the expected bits by **and** ing it to 0. And and in y, we just
get expected bits we want by **and** ing it to 1 and we OR the two expressions and
thus get the result.


**Why left shift?**

We left shift because we want it from a position p.

Suppose we want two bits from position 4, we we need to our bit patterns to be
like this::

	0001 1000
	   
	7654 3210

In the above, from position 4, we have 2 bits set 1 and rest 0.

In order to do this, we get two bits at the right most position::

	~(~0 << n)
	0000 0011

And then we shift it by position 4 using the expression p+1-n::

	~(~0 << n) << (4+1-n)
	0000 0011 << (5-2)
	0000 0011 << 3
	0 0011 000
	0001 1000	

So we determined our expected bits and we can follow the rest for the program.



Let's get concrete and work out the program using the values::

    x = 1111 1111 (= 255 )
    p = 3
    y = 0000 0000 (= 0)
    n = 4

::

	setbits(unsigned x,int p,int n,unsigned y);

Right most 4 bits of y = 0000
So, we our return value should be::

  = 1111 0000
  = 240

Let's follow how the program determines it. We take the LHS of `|` ::

	(x & ~(~(~0 << n) << (p+1-n)))

	p+1-n = 3 + 1 - 4
	      = 0

	(~0 << n)
	      = (~ 0000 0000 << 4)
	      = (1111 1111 << 4)
	      = (1111 0000)

	~(~0 << n)
          = ~(1111 0000)
          = 0000 1111 

	(~(~0 << n) << (p+1-n))
          = 0000 1111 << 0
          = 0000 1111

	~(~(~0 << n) << (p+1-n))         
		  = ~ (0000 1111)
		  = 1111 0000

	(x & ~(~(~0 << n) << (p+1-n)))
		  =  1111 1111 & 1111 0000
		  =  1111 0000

Now we take the RHS of `|` ::

	(( y & ~(~0<<n)) << (p+1-n))

	(p + 1 - n) = 0

	~(~0 << n)  = 0000 1111

	( y & ~(~0<<n)) 
            = 0000 0000 & 0000 1111
            = 0000 0000

	(( y & ~(~0<<n)) << (p+1-n))           
			
			= 0000 0000 << 4
			= 0000 0000

We write the entire expression::

	(x & ~(~(~0 << n) << (p+1-n))) | (( y & ~(~0<<n)) << (p+1-n));
		    = 1111 0000  | 0000 0000
		    = 1111 0000

Converting 1111 0000 to decimal gives us 240 and that is answer.



.. seealso::

   * :c-suggest-improve:`Ex_2.6_setbits.c`
   * :c-better-explain:`Ex_2.6_setbits.rst`
