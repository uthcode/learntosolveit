=========================
5.7 Readlines using array
=========================

Question
========

Rewrite readlines to store lines in an array supplied by main, rather than
calling alloc to maintain storage. How much faster is the program?


.. literalinclude:: cprogs/ex_5.7_readlines_using_array.c
   :language: c
   :tab-width: 4

Explanation
===========

This uses the same qsort program. But instead of calculating the memory required
using the alloc operator. It sends a predefined amount of memory from the main
program.

It's a line sorting program written in C that reads input lines, sorts them alphabetically, and prints them out.

::

    $ ./ex_5.7_readlines_using_array
    this is a line.
    Another line.
    Good Line.
    Abacus
    Backgammon.
    ^D
    Abacus
    Another line.
    Backgammon.
    Good Line.
    this is a line.






Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20pointer%20array%20into%20shared%20storage%3B%20swap%20pointers%20to%20sort%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20store%5B14%5D%20%3D%20%22banana%5C0apple%22%3B%0A%20%20%20%20char%20%2Alines%5B2%5D%3B%0A%20%20%20%20lines%5B0%5D%20%3D%20store%3B%0A%20%20%20%20lines%5B1%5D%20%3D%20store%20%2B%207%3B%0A%20%20%20%20if%20%28strcmp%28lines%5B0%5D%2C%20lines%5B1%5D%29%20%3E%200%29%20%7B%0A%20%20%20%20%20%20%20%20char%20%2Atmp%20%3D%20lines%5B0%5D%3B%20lines%5B0%5D%20%3D%20lines%5B1%5D%3B%20lines%5B1%5D%20%3D%20tmp%3B%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22%25s%5Cn%25s%5Cn%22%2C%20lines%5B0%5D%2C%20lines%5B1%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
