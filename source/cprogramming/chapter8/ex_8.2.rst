==========================================
8.2 Rewrite fopen and _fillbuf with fields
==========================================

Question
========

Rewrite fopen and _fillbuf with fields instead of explicit bit operations.
Compare code size and execution speed.

.. literalinclude:: cprogs/ex_8.2.c
   :language: c

Explanation
===========

This is a low level implementation of fopen and _fillbuf with enums and fields.





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20FILE%20flag%20bits%20%E2%80%94%20_READ%2F_WRITE%2F_EOF%2F_ERR%20encoded%20as%20bit%20fields%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20_READ%20%3D%2001%2C%20_WRITE%20%3D%2002%2C%20_EOF%20%3D%20010%2C%20_ERR%20%3D%20020%3B%0A%20%20%20%20int%20flag%3B%0A%20%20%20%20%2F%2A%20stdin-like%3A%20read-only%20%2A%2F%0A%20%20%20%20flag%20%3D%20_READ%3B%0A%20%20%20%20printf%28%22stdin%3A%20readable%3D%25d%20writable%3D%25d%5Cn%22%2C%0A%20%20%20%20%20%20%20%20%20%20%20%28flag%20%26%20_READ%29%20%20%21%3D%200%2C%20%28flag%20%26%20_WRITE%29%20%21%3D%200%29%3B%0A%20%20%20%20%2F%2A%20stdout-like%3A%20write-only%20%2A%2F%0A%20%20%20%20flag%20%3D%20_WRITE%3B%0A%20%20%20%20printf%28%22stdout%3A%20readable%3D%25d%20writable%3D%25d%5Cn%22%2C%0A%20%20%20%20%20%20%20%20%20%20%20%28flag%20%26%20_READ%29%20%20%21%3D%200%2C%20%28flag%20%26%20_WRITE%29%20%21%3D%200%29%3B%0A%20%20%20%20%2F%2A%20simulate%20EOF%20reached%20%2A%2F%0A%20%20%20%20flag%20%7C%3D%20_EOF%3B%0A%20%20%20%20printf%28%22after%20EOF%3A%20eof%3D%25d%20err%3D%25d%5Cn%22%2C%0A%20%20%20%20%20%20%20%20%20%20%20%28flag%20%26%20_EOF%29%20%21%3D%200%2C%20%28flag%20%26%20_ERR%29%20%21%3D%200%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
