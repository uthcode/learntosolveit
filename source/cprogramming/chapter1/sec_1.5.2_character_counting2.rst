=========================
1.5.2 Character Counting2
=========================


Program
-------


.. coderun:: cprogs/sec_1.5.2_character_counting2.c
   :language: c


Explanation
-----------

In this program we are going to count the number of characters present in the
input. The program does the counting by setting nc to 0 in the beginning. As the
program enters for loop condition (nc = 0; getchar() != EOF; ++nc).  When nc
hits end of the document it prints the number of characters in the file.


----

This document was updated on |today|

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20count%20characters%20with%20for%20loop%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22hi%5Cn%22%3B%0A%20%20%20%20double%20nc%3B%0A%20%20%20%20int%20i%20%3D%200%3B%0A%20%20%20%20for%20%28nc%20%3D%200%3B%20s%5Bi%2B%2B%5D%3B%20%2B%2Bnc%29%3B%0A%20%20%20%20printf%28%22%25.0f%5Cn%22%2C%20nc%29%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
