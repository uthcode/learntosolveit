=====================================
5.2 get next float from input to \*pn
=====================================

Question
========

Write getfloat, the floating-point analog of getint. What type does getfloat
return as its function value?

.. coderun:: cprogs/ex_5.2_getfloat.c
   :language: c
   :tab-width: 4

Explanation
===========

The function `getfloat` is similar to the `getint` function, wherein instead of
getting an integer, we get a float value.

We declare an array, `float array[SIZE]` in which we store the float values and
the the float value is got from the  function `int getfloat(float *);`

The function getfloat, sends a pointer to the float and stores a float value in
the array. The mechanism of how it gets a float is defined in the `getfloat`
function.

The curx of how the float is got is in this snippet. The function reads all the
characters and converts to a float and stores them in the `*pn` pointer. Then it
reads the decimal part and for all the digits after the decimal point, it
increments the power by 10. For e.g. if the decimal was `0.123` for 3 decimal
digits, the power will be 10 * 10 * 10 = 1000.


::

    for(*pn = 0.0 ; isdigit(c);c=getch())
        *pn = 10.0 * *pn + (c - '0');
    if( c == '.')
        c = getch();

    for(power=1.0;isdigit(c);c=getch())
    {
        *pn = 10.0 * *pn + (c - '0');   /* fractional part */
        power *= 10.0;
    }

    *pn  *= sign / power;


Finally to get the decimal representation along with sign, then the number in pn
is divided by power and multiplied by sign, i.e, `*pn = ((*pn * sign) / power)`
and thus the correct float value is obtained.

The float value is stored in the array index that was sent from the main
program.





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20getfloat%20reads%20a%20floating-point%20number%20via%20a%20pointer%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20getfloat%28float%20%2Apn%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%223.14%22%3B%0A%20%20%20%20int%20i%20%3D%200%3B%0A%20%20%20%20float%20pow%20%3D%201.0%3B%0A%20%20%20%20%2Apn%20%3D%200%3B%0A%20%20%20%20while%20%28s%5Bi%5D%20%3E%3D%20%270%27%20%26%26%20s%5Bi%5D%20%3C%3D%20%279%27%29%20%7B%20%2Apn%20%3D%20%2Apn%20%2A%2010%20%2B%20%28s%5Bi%5D%20-%20%270%27%29%3B%20i%2B%2B%3B%20%7D%0A%20%20%20%20if%20%28s%5Bi%5D%20%3D%3D%20%27.%27%29%20%7B%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20while%20%28s%5Bi%5D%20%3E%3D%20%270%27%20%26%26%20s%5Bi%5D%20%3C%3D%20%279%27%29%20%7B%20pow%20%2A%3D%2010%3B%20%2Apn%20%2B%3D%20%28s%5Bi%5D%20-%20%270%27%29%20%2F%20pow%3B%20i%2B%2B%3B%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20return%20i%20%3E%200%20%3F%201%20%3A%200%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20float%20n%3B%0A%20%20%20%20if%20%28getfloat%28%26n%29%20%3E%200%29%20printf%28%22%25.2f%5Cn%22%2C%20n%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
