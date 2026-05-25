================================
8.3 _flushbuf, fflush and fclose
================================

Question
========

Design and write _flushbuf, fflush, and fclose.

**inprogress**

.. coderun:: cprogs/ex_8.3.c
   :language: c

Explanation
===========

This is an internal implementation of `_flushbuf`, `fflush`, and `fclose`. This is implemented by defining a structure called
`_iobuf`, making it point to a file pointer, and reading the contents as a linked list implementation, each time allocating a memory to `base` in the iobuf.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20buffered%20I%2FO%20%E2%80%94%20getchar%20reads%20from%20a%20buffer%2C%20refills%20when%20empty%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20buf%5B%5D%20%3D%20%22hi%5Cn%22%3B%0A%20%20%20%20int%20pos%20%3D%200%2C%20cnt%20%3D%203%3B%0A%20%20%20%20while%20%28cnt--%20%3E%200%29%20%7B%0A%20%20%20%20%20%20%20%20int%20c%20%3D%20%28unsigned%20char%29buf%5Bpos%2B%2B%5D%3B%0A%20%20%20%20%20%20%20%20putchar%28c%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
