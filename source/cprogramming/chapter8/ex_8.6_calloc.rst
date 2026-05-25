===================================
8.6 Write calloc, by calling malloc
===================================

Question
========

The standard library function calloc(n,size) returns a pointer to n objects of
size size, with the storage initialized to zero. Write calloc, by calling malloc
or by modifying it.

.. coderun:: cprogs/ex_8.6_calloc.c
   :language: c
   :tab-width: 4

Explanation
===========

This is a custom implmentation of calloc. The standard library function calloc(n,size) returns a pointer to n objects
of `size`, with the storage intialized to zero.

This program writes calloc,by utilizing malloc.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20calloc%20allocates%20n%2Asize%20bytes%20and%20zeros%20them%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0Avoid%20%2Amycalloc%28unsigned%20n%2C%20unsigned%20size%29%20%7B%0A%20%20%20%20unsigned%20i%2C%20nb%20%3D%20n%20%2A%20size%3B%0A%20%20%20%20char%20%2Ap%2C%20%2Aq%3B%0A%20%20%20%20if%20%28%28p%20%3D%20q%20%3D%20malloc%28nb%29%29%20%21%3D%20NULL%29%0A%20%20%20%20%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20nb%3B%20i%2B%2B%29%20%2Ap%2B%2B%20%3D%200%3B%0A%20%20%20%20return%20q%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20%2Aarr%20%3D%20mycalloc%283%2C%20sizeof%28int%29%29%3B%0A%20%20%20%20if%20%28arr%29%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22%25d%20%25d%20%25d%5Cn%22%2C%20arr%5B0%5D%2C%20arr%5B1%5D%2C%20arr%5B2%5D%29%3B%0A%20%20%20%20%20%20%20%20free%28arr%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
