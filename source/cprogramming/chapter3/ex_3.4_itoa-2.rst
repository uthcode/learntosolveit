===========================================
3.4 itoa to handle largest negative integer
===========================================

Question
========

In a two's complement number representation, our version of itoa does not handle
the largest negative number,  that is, the value of n equal to -(2wordsize-1).
Explain why not. Modify it to print that value correctly,  regardless of the
machine on which it runs.

The previous version of itoa was this

.. coderun:: cprogs/ex_3.4_itoa-2.c
   :language: c
   :tab-width: 4

Explanation
===========

In this version of itoa, which involves a largest negative number, we first
store the number itself in an integer called sign. Then get numbers from
unittest by doing `n%10`, get the unsigned number by doing a `abs` value and get
character by adding it to `0`.

Thus we go about converting each digit starting from unit place to a character.
Once this process is over. We check if we were converting negative number, by
checking if the sign is less than 0, if it was, we add a `-` to the string.

And then we do a simple `reverse` of the string to get our `itoa`.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20itoa%20using%20do-while%20to%20handle%20INT_MIN%20correctly%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0A%23define%20abs%28x%29%20%28%28x%29%20%3E%200%20%3F%20%28x%29%20%3A%20-%28x%29%29%0Avoid%20reverse%28char%20s%5B%5D%29%20%7B%0A%20%20%20%20int%20i%20%3D%200%2C%20j%20%3D%20strlen%28s%29%20-%201%2C%20c%3B%0A%20%20%20%20for%20%28%3B%20i%20%3C%20j%3B%20i%2B%2B%2C%20j--%29%20c%20%3D%20s%5Bi%5D%2C%20s%5Bi%5D%20%3D%20s%5Bj%5D%2C%20s%5Bj%5D%20%3D%20c%3B%0A%7D%0Avoid%20itoa%28int%20n%2C%20char%20s%5B%5D%29%20%7B%0A%20%20%20%20int%20i%20%3D%200%2C%20sign%20%3D%20n%3B%0A%20%20%20%20do%20%7B%20s%5Bi%2B%2B%5D%20%3D%20abs%28n%20%25%2010%29%20%2B%20%270%27%3B%20%7D%20while%20%28%28n%20%2F%3D%2010%29%20%21%3D%200%29%3B%0A%20%20%20%20if%20%28sign%20%3C%200%29%20s%5Bi%2B%2B%5D%20%3D%20%27-%27%3B%0A%20%20%20%20s%5Bi%5D%20%3D%20%27%5C0%27%3B%0A%20%20%20%20reverse%28s%29%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20str%5B20%5D%3B%0A%20%20%20%20itoa%28-42%2C%20str%29%3B%0A%20%20%20%20printf%28%22%25s%5Cn%22%2C%20str%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
