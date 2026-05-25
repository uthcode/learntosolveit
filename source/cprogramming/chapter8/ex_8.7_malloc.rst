============================
8.7 Error checking by malloc
============================

Question
========

Malloc accepts a size request without checking its plausibility; free believes
that the block it is asked to free contains a valid size field. Improve these
routines so they make more pains with error checking.

.. coderun:: cprogs/ex_8.7_malloc.c
   :language: c

Explanation
===========

This is an error checking implementation of malloc. If it cannot allocate more bytes, it will throw an error

::

    if (nbytes > MAXBYTES) {
        fprintf(stderr, "alloc: can't allocate more than %u bytes\n", MAXBYTES);
        return NULL;
    }


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20malloc%20uses%20a%20union%20header%20to%20ensure%20proper%20alignment%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Atypedef%20long%20Align%3B%0Aunion%20header%20%7B%0A%20%20%20%20struct%20%7B%20union%20header%20%2Aptr%3B%20unsigned%20size%3B%20%7D%20s%3B%0A%20%20%20%20Align%20x%3B%0A%7D%3B%0Atypedef%20union%20header%20Header%3B%0Aint%20main%28void%29%20%7B%0A%20%20%20%20printf%28%22Header%20size%3A%20%25zu%20bytes%5Cn%22%2C%20sizeof%28Header%29%29%3B%0A%20%20%20%20printf%28%22Align%20%20size%3A%20%25zu%20bytes%5Cn%22%2C%20sizeof%28Align%29%29%3B%0A%20%20%20%20Header%20h%3B%0A%20%20%20%20h.s.size%20%3D%204%3B%0A%20%20%20%20h.s.ptr%20%20%3D%20NULL%3B%0A%20%20%20%20printf%28%22Block%20size%3A%20%25u%5Cn%22%2C%20h.s.size%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
