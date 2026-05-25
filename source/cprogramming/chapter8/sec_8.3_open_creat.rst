=========================
8.3 open and create calls
=========================

Question
========

Demonstrate the ``cp`` like program which copies the contents of one file to another.


.. coderun:: cprogs/sec_8.3_open_creat.c
   :language: c


Explanation
===========

::

    while ((n = read(f1, buf, BUFSIZE)) > 0)
        if (write(f2, buf, n) != n)

Reads up to BUFSIZE bytes from source file into buffer. Writes the same number of bytes to destination file. continues
until entire file is copied

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20file%20copy%20using%20open%2Fcreat%20%E2%80%94%20read%20chunks%2C%20write%20chunks%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20src%5B%5D%20%3D%20%22hello%5Cn%22%3B%0A%20%20%20%20char%20buf%5B10%5D%3B%0A%20%20%20%20int%20n%20%3D%206%2C%20i%3B%0A%20%20%20%20printf%28%22Copying%20%25d%20bytes%3A%5Cn%22%2C%20n%29%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20n%3B%20i%2B%2B%29%20buf%5Bi%5D%20%3D%20src%5Bi%5D%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20n%3B%20i%2B%2B%29%20putchar%28buf%5Bi%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
