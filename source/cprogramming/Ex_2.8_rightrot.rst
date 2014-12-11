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

Explanation
===========

We need to get the right most bit of the number provided.

First we get the right n bits at one time.

::
    rbit = x << (wordlength() - n);

Once we get the right n bits, in order to rotate the value of x, we right
shift x for n bits and then OR the result of x with the rbit determined in the previous
step.

::

        x = x >> n;
        x = x | rbit;

 For the same example.

::

    n is between 0 - wordlength()

    condition 1.when  (n == 0) or (n == wordlength()) 

                rightrot(x, 0) == x

    condition 2. when  (n > 0) and (n < wordlength())	like n = 3

                x  = 0001 1001
                the right n bits will be 001.
                the right rightrot(x,n)result should be 0010 0011

                x << (wordlength() - n) = 0001 1001 << (8 - 3)
                = 0001 1001 << 5
                = 0010 0000

So we have got the right most n bits set.Now we right x by 1 and OR the rbit with x.

::

    x >> n =  0001 1001 >> 3
    =  0000 0011

    x | rbit = 0000 0011 | 0010 0000
    = 0010 0011

Which is our expected result.

::

    condition 3. when (n > wordlength())	like n = 12

The Compiler will auto transfer "n" to "n % wordlength()", n will be 3, then see "n" as condition 2.
The result should be correct too!

::
    condition 4.    when n < 0	(which is not Often use)

The result will mirror the function,the rightrot(x,n) function will move the left most n(n > 0)bits to the right
side ，the function should called leftrot(x,n).

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_2.8_rightrot.c`
   * :c-better-explain:`Ex_2.8_rightrot.rst`
