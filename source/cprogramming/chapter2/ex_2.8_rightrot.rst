===================================================================================
Exercise 2.8-returns the value of the integer x rotated to the right by n positions
===================================================================================

Question
========

Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.

.. literalinclude:: cprogs/ex_2.8_rightrot.c
   :language: c

Explanation
===========

We need to get the right most bit of the number provided.

First we get the right n bits at one time.

::

    rbit = x << (wordlength() - n);

Once we get the right n bits, in order to rotate the value of x, we right shift
x for n bits and then OR the result of x with the rbit determined in the
previous step.

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

So we have got the right most n bits set.Now we right x by 1 and OR the rbit
with x.

::

    x >> n =  0001 1001 >> 3
    =  0000 0011

    x | rbit = 0000 0011 | 0010 0000
    = 0010 0011

Which is our expected result.

::

    condition 3. when (n > wordlength())	like n = 12

The Compiler will auto transfer "n" to "n % wordlength()", n will be 3, then
see "n" as condition 2. The result should be correct too!

::

    condition 4.    when n < 0	(which is not Often use)

The result will mirror the function,the rightrot(x,n) function will move the
left most n(n > 0)bits to the right side ，the function should called
leftrot(x,n).

Visualization
=============

.. raw:: html

    <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%0Aunsigned%20rightrot%28unsigned%20x,%20int%20n%29%3B%0A%0Aint%20main%28void%29%20%7B%0A%20%20%20%20printf%28%22%25u%22,%20%28unsigned%29rightrot%28%28unsigned%298,%20%28int%291%29%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D%0A%0A/*%20rightrot%3A%20rotate%20x%20to%20right%20by%20n%20bit%20positions%20*/%0A%0Aunsigned%20rightrot%28unsigned%20x,%20int%20n%29%20%7B%0A%20%20%20%20int%20wordlength%28void%29%3B%0A%20%20%20%20unsigned%20rbit%3B%20/*%20rightmost%20bit%20*/%0A%0A%20%20%20%20rbit%20%3D%20x%20%3C%3C%20%28wordlength%28%29%20-%20n%29%3B%0A%20%20%20%20x%20%3D%20x%20%3E%3E%20n%3B%0A%20%20%20%20x%20%3D%20x%20%7C%20rbit%3B%0A%0A%20%20%20%20return%20x%3B%0A%7D%0A%0Aint%20wordlength%28void%29%20%7B%0A%20%20%20%20int%20i%3B%0A%20%20%20%20unsigned%20v%20%3D%20%28unsigned%29~0%3B%0A%0A%20%20%20%20for%20%28i%20%3D%201%3B%20%28v%20%3D%20v%20%3E%3E%201%29%20%3E%200%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20%3B%0A%20%20%20%20return%20i%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>
