==============================
8.8 bfree maintained by malloc
==============================

Question
========

Write a routine bfree(p,n) that will free any arbitrary block p of n characters
into the free list maintained by malloc and free. By using bfree, a user can add
a static or external array to the free list at any time.

.. coderun:: cprogs/ex_8.8_bfree.c
   :language: c


Explanation
===========

This program manages the memory blocks, takes care of the alignment, and for the smaller memory blocks it maintains a wtbfree method
that helps align smaller memory blocks.

This memory allocation program is simliar how to parking lot orchestrator can allocate park spots for regular sized cars
and smaller vehicles like bikes, and it will squeeze the spots together to make room for bigger car or additional small sized bikes.
Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20compute%20alignment%20padding%20to%20align%20a%20block%20to%20long%20boundary%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Atypedef%20long%20Align%3B%0A%23define%20ALIGN_PAD%28p%29%20%28%28sizeof%28Align%29%20-%20%28%28unsigned%29%28long%29%28p%29%20%25%20sizeof%28Align%29%29%29%20%25%20sizeof%28Align%29%29%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20buf%5B20%5D%3B%0A%20%20%20%20int%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%3D%203%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20char%20%2Ap%20%3D%20buf%20%2B%20i%3B%0A%20%20%20%20%20%20%20%20unsigned%20pad%20%3D%20ALIGN_PAD%28p%29%3B%0A%20%20%20%20%20%20%20%20printf%28%22offset%3D%25d%2C%20pad%3D%25u%2C%20aligned_offset%3D%25d%5Cn%22%2C%20i%2C%20pad%2C%20i%20%2B%20%28int%29pad%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
