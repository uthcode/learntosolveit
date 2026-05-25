===================================================
3.5 function itob, converts a integer into a string
===================================================

Question
========

Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s
as a hexadecimal integer in s.

.. coderun:: cprogs/ex_3.5_itob.c
   :language: c

Explanation
===========


In this, we are specifically targetting the conversion to base 16, though we
should be able to extend the program to any base.

As before we get the number and store it in sign, then we get the remainder of
the number after dividing by base `b`.  We covert the number we have gotten to
hexadecimal by this expression ` (j <= 9)?j+'0':j+'a'-10`, which states that if
the number is less than 10, return the string representation of it, otherwise
subtract 10 from it and add 'a' to get the hexadecimal representation of 10 to
15 that (a,b,c,d,e,f).

We store these in a string and it number was a negative number, we append '-'
sign to it. We get the result, by reversing the string which we constructed.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20convert%20integer%20to%20string%20in%20arbitrary%20base%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0Avoid%20reverse%28char%20s%5B%5D%29%20%7B%0A%20%20%20%20int%20i%20%3D%200%2C%20j%20%3D%20strlen%28s%29%20-%201%2C%20c%3B%0A%20%20%20%20for%20%28%3B%20i%20%3C%20j%3B%20i%2B%2B%2C%20j--%29%20c%20%3D%20s%5Bi%5D%2C%20s%5Bi%5D%20%3D%20s%5Bj%5D%2C%20s%5Bj%5D%20%3D%20c%3B%0A%7D%0Avoid%20itob%28int%20n%2C%20char%20s%5B%5D%2C%20int%20b%29%20%7B%0A%20%20%20%20int%20i%20%3D%200%2C%20j%2C%20sign%3B%0A%20%20%20%20if%20%28%28sign%20%3D%20n%29%20%3C%200%29%20n%20%3D%20-n%3B%0A%20%20%20%20do%20%7B%0A%20%20%20%20%20%20%20%20j%20%3D%20n%20%25%20b%3B%0A%20%20%20%20%20%20%20%20s%5Bi%2B%2B%5D%20%3D%20%28j%20%3C%3D%209%29%20%3F%20j%20%2B%20%270%27%20%3A%20j%20%2B%20%27a%27%20-%2010%3B%0A%20%20%20%20%7D%20while%20%28%28n%20%2F%3D%20b%29%20%3E%200%29%3B%0A%20%20%20%20if%20%28sign%20%3C%200%29%20s%5Bi%2B%2B%5D%20%3D%20%27-%27%3B%0A%20%20%20%20s%5Bi%5D%20%3D%20%27%5C0%27%3B%0A%20%20%20%20reverse%28s%29%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20str%5B20%5D%3B%0A%20%20%20%20itob%2842%2C%20str%2C%2016%29%3B%0A%20%20%20%20printf%28%22%25s%5Cn%22%2C%20str%29%3B%20%20%2F%2A%202a%20%2A%2F%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
