==========
1.6 Arrays
==========


Program
=======

.. coderun:: cprogs/sec_1.6_arrays.c
   :language: c

Explanation
===========

This section introduces arrays. Arrays in C hold a number of same typed
variables into a one entity and are indexed by their position. In this program
it is demonstrated by holding the count of number of digits in the array `int
ndigit[10];`  This program lets us count the digits, whitespace and others.
There are 10 digits, ranging from 0 to 9, so we create a array, ndigits which
can hold 10 digits. In the program we getchar() and for characters between '0'
and '9', we take it and substract '0' from it so that we can get the value and
we increment array index at that value.

In the end, we print the values stored in the array.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20count%20digits%2C%20whitespace%2C%20and%20other%20chars%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22hi%2042%22%3B%0A%20%20%20%20int%20i%2C%20nwhite%20%3D%200%2C%20nother%20%3D%200%3B%0A%20%20%20%20int%20ndigit%5B10%5D%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%2010%3B%20%2B%2Bi%29%20ndigit%5Bi%5D%20%3D%200%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20s%5Bi%5D%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20%20%20%20%20int%20c%20%3D%20%28unsigned%20char%29s%5Bi%5D%3B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3E%3D%20%270%27%20%26%26%20c%20%3C%3D%20%279%27%29%20%2B%2Bndigit%5Bc-%270%27%5D%3B%0A%20%20%20%20%20%20%20%20else%20if%20%28c%20%3D%3D%20%27%20%27%20%7C%7C%20c%20%3D%3D%20%27%5Ct%27%29%20%2B%2Bnwhite%3B%0A%20%20%20%20%20%20%20%20else%20%2B%2Bnother%3B%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22digits%20%3D%22%29%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%2010%3B%20%2B%2Bi%29%20printf%28%22%20%25d%22%2C%20ndigit%5Bi%5D%29%3B%0A%20%20%20%20printf%28%22%2C%20white%3D%25d%2C%20other%3D%25d%5Cn%22%2C%20nwhite%2C%20nother%29%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
