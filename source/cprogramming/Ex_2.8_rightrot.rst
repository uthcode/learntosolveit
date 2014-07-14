===================================================================================
Exercise 2.8-returns the value of the integer x rotated to the right by n positions
===================================================================================

Question
========

Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.

.. literalinclude:: ../../languages/cprogs/Ex_2.8_rightrot.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_2.8_rightrot.c
   :language: c
   :codesite: ideone

Explaination
============

We need to get the right most bit of the number provided.

The right most bit can be got by left shifting all the digits except the right
most. This is done by first capturing wordlength() and then left shifting the x
& 1 with wordlength() -1

::

        rbit = (x & 1) << (wordlength()-1);

 The resultant value will be something like 1000 0000 for any right most bit of 1.

Once we get the right most bit, in order to rotate the value of x, we right
shift x and then OR the result of x with the rbit determined in the previous
step.

::

        x = x >> 1;
        x = x | rbit;

For example.

Let's take **x** as 0001 1001 and when it is right rotated we will get the
result as 10001 100 (rearranging that: 1000 1100)


First we calculate the rbit::

		(x & 1) = 0001 1001 & 1111 1111
		        = 0001 1001

		(x & 1) << (wordlength() -1) = 0001 1001 << (8 - 1)
							         = 0001 1001 << 7
							         = 1 000 0000
							         = 1000 0000

So we have got the right most bit set. Now we right x by 1 and OR the rbit with x.

::

		x >> 1 =  0001 1001 >> 1
			   =  0 0001 100
			   =  0000 1100

		x | rbit = 0000 1100 | 1000 0000
			     = 1000 1100


Which is our expected result.

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_2.8_rightrot.c`
   * :c-better-explain:`Ex_2.8_rightrot.rst`
