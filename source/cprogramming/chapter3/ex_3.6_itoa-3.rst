=========================
3.6 itoa with field width
=========================

Question
========

Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with
blanks on the left if necessary to make it wide enough.

.. coderun:: cprogs/ex_3.6_itoa-3.c
   :language: c
   :tab-width: 4

Explanation
===========

Note: For negative numbers the negative sign is written close to the number
instead of before the padded width. This is ``itoa`` conversion with padding. We
specify the width of the number we want in ``w`` and as before, we proceed with
``itoa``, wherein extract the unit digit (n ``% 10``), convert it to character and
store it in a character array. If it were a negative number we store the sign
too. We keep track of number of digits in the number in a variable, ``i`` and for
the remaining digits, for ``i < w``, we append the space character " ".

We reverse the string thus constructed for our result.


Visualize It
============

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=/*%20a%20function%20of%20itoa,%20which%20accepts%20the%20third%20argument%20as%20the%20width%20of%20the%20number.%0Athe%20string%20representation%20is%20padded%20with%20blanks%20in%20the%20left%20to%20get%20the%20%20required%20width%20*/%0A%0A%23include%3Cstdio.h%3E%0A%23include%3Cstring.h%3E%0A%0A%23define%20MAXLIMIT%20100%0A%0Avoid%20itoa%28int%20n,char%20s%5B%5D,int%20w%29%3B%0Avoid%20reverse%28char%20s%5B%5D%29%3B%0A%0Aint%20main%28void%29%0A%7B%0A%20%20%20%20int%20number,width%3B%0A%20%20%20%20char%20str%5BMAXLIMIT%5D%3B%0A%0A%20%20%20%20number%3D%20-343565%3B%0A%20%20%20%20width%3D10%3B%0A%20%20%20%20%0A%20%20%20%20itoa%28number,str,width%29%3B%0A%0A%20%20%20%20printf%28%22%25s%22,str%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D%0A%0Avoid%20itoa%28int%20n,char%20s%5B%5D,int%20w%29%0A%7B%0A%20%20%20%20int%20i,sign%3B%0A%0A%20%20%20%20if%28%28sign%3Dn%29%20%3C%200%29%0A%20%20%20%20%20%20%20%20n%20%3D%20-n%3B%0A%20%20%20%20i%3D0%3B%0A%0A%20%20%20%20do%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20s%5Bi%2B%2B%5D%20%3D%20%28n%20%2510%29%20%2B%20'0'%3B%0A%0A%20%20%20%20%7Dwhile%28%28n/%3D10%29%3E0%29%3B%0A%0A%20%20%20%20if%28sign%20%3C0%29%0A%20%20%20%20%20%20%20%20s%5Bi%2B%2B%5D%3D'-'%3B%0A%0A%20%20%20%20while%28i%3Cw%29%0A%20%20%20%20%20%20%20%20s%5Bi%2B%2B%5D%3D'%20'%3B%0A%0A%20%20%20%20s%5Bi%5D%3D'%5C0'%3B%0A%0A%20%20%20%20reverse%28s%29%3B%0A%7D%0A%0Avoid%20reverse%28char%20s%5B%5D%29%0A%7B%0A%20%20%20%20int%20i,j,c%3B%0A%0A%20%20%20%20for%28i%3D0,j%3Dstrlen%28s%29-1%3Bi%3Cj%3Bi%2B%2B,j--%29%0A%20%20%20%20%20%20%20%20c%3Ds%5Bi%5D,s%5Bi%5D%3Ds%5Bj%5D,s%5Bj%5D%3Dc%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=true&curInstr=0&heapPrimitives=false&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=true"> </iframe>


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20itoa%20with%20minimum%20field%20width%20padding%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0Avoid%20reverse%28char%20s%5B%5D%29%20%7B%0A%20%20%20%20int%20i%20%3D%200%2C%20j%20%3D%20strlen%28s%29%20-%201%2C%20c%3B%0A%20%20%20%20for%20%28%3B%20i%20%3C%20j%3B%20i%2B%2B%2C%20j--%29%20c%20%3D%20s%5Bi%5D%2C%20s%5Bi%5D%20%3D%20s%5Bj%5D%2C%20s%5Bj%5D%20%3D%20c%3B%0A%7D%0Avoid%20itoa%28int%20n%2C%20char%20s%5B%5D%2C%20int%20w%29%20%7B%0A%20%20%20%20int%20i%20%3D%200%2C%20sign%3B%0A%20%20%20%20if%20%28%28sign%20%3D%20n%29%20%3C%200%29%20n%20%3D%20-n%3B%0A%20%20%20%20do%20%7B%20s%5Bi%2B%2B%5D%20%3D%20%28n%20%25%2010%29%20%2B%20%270%27%3B%20%7D%20while%20%28%28n%20%2F%3D%2010%29%20%3E%200%29%3B%0A%20%20%20%20if%20%28sign%20%3C%200%29%20s%5Bi%2B%2B%5D%20%3D%20%27-%27%3B%0A%20%20%20%20while%20%28i%20%3C%20w%29%20s%5Bi%2B%2B%5D%20%3D%20%27%20%27%3B%0A%20%20%20%20s%5Bi%5D%20%3D%20%27%5C0%27%3B%0A%20%20%20%20reverse%28s%29%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20str%5B20%5D%3B%0A%20%20%20%20itoa%2842%2C%20str%2C%206%29%3B%0A%20%20%20%20printf%28%22%5B%25s%5D%5Cn%22%2C%20str%29%3B%20%20%2F%2A%20%5B%20%20%20%2042%5D%20%2A%2F%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
