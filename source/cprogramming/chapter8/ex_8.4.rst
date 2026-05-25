===================
8.4 implement fseek
===================

Question
========

The standard library function:

	``int fseek(FILE *fp, long offset, int origin)``

**inprogress**


.. literalinclude:: cprogs/ex_8.4.c
   :language: c
   :tab-width: 4

Explanation
===========

This uses three fields

::

    #define SEEK_SET 0
    #define SEEK_CUR 1
    #define SEEK_END 2

and determines where we are in the file using the file seek operations.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20fseek%20must%20flush%2Fdiscard%20buffer%20%E2%80%94%20cnt%20reset%20to%200%2C%20ptr%20reset%20to%20base%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20base%5B8%5D%20%3D%20%22abcdefg%22%3B%0A%20%20%20%20char%20%2Aptr%20%3D%20base%20%2B%203%3B%20%2F%2A%203%20chars%20already%20consumed%20%2A%2F%0A%20%20%20%20int%20cnt%20%3D%204%3B%20%20%20%20%20%20%20%20%20%20%20%2F%2A%204%20chars%20remaining%20in%20buffer%20%2A%2F%0A%20%20%20%20printf%28%22before%20seek%3A%20cnt%3D%25d%20ptr_offset%3D%25d%5Cn%22%2C%20cnt%2C%20%28int%29%28ptr%20-%20base%29%29%3B%0A%20%20%20%20%2F%2A%20fseek%3A%20discard%20buffered%20read%20data%20%2A%2F%0A%20%20%20%20cnt%20%3D%200%3B%0A%20%20%20%20ptr%20%3D%20base%3B%0A%20%20%20%20printf%28%22after%20seek%3A%20%20cnt%3D%25d%20ptr_offset%3D%25d%5Cn%22%2C%20cnt%2C%20%28int%29%28ptr%20-%20base%29%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
