================
1.7 Value of EOF
================

Question
--------

Write a Program to print the value of EOF.

Solution
--------

.. coderun:: cprogs/ex_1.7_eofval.c
   :language: c

Explanation
===========

1. Since EOF is an integer, we can print it with %d format in the printf. 2. EOF
value is printed as -1.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20EOF%20is%20a%20macro%20defined%20in%20stdio.h%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20printf%28%22The%20value%20of%20EOF%20is%20%25d%5Cn%22%2C%20EOF%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
