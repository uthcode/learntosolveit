================================================
Exercise 5.2 - get next float from input to \*pn
================================================

Question
========

Write getfloat, the floating-point analog of getint. What type does getfloat
return as its function value?

.. literalinclude:: cprogs/ex_5.2_getfloat.c
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




