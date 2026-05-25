======================
1.4 Symbolic Constants
======================

Program
=======

.. coderun:: cprogs/sec_1.4_symbolic.c
   :language: c

Explanation
===========

In this program we are going to convert a given Fahrenheit temperature to
Celsius temperature using the formula C=(5/9)(F-32). We define some some
**symbolic constants** in the beginning of the program so that they can be used
in the later stages of the program. The constants that are defined in the program are:
LOWER,UPPER,STEP, . The label LOWER is assigned the value 0 similarly UPPER
to 300, STEP to 20. So when the program enters the for loop it checks whether
fahr <= UPPER, and the increments fahr using STEP in each iteration.

*symbolic constants* are substituted inline in the program during pre-processing
phase of compilation.
Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20symbolic%20constants%20with%20%23define%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23define%20LOWER%200%0A%23define%20UPPER%2040%0A%23define%20STEP%2020%0Aint%20main%28%29%20%7B%0A%20%20%20%20int%20fahr%3B%0A%20%20%20%20for%20%28fahr%20%3D%20LOWER%3B%20fahr%20%3C%3D%20UPPER%3B%20fahr%20%3D%20fahr%20%2B%20STEP%29%0A%20%20%20%20%20%20%20%20printf%28%22%253d%20%256.1f%5Cn%22%2C%20fahr%2C%20%285.0%2F9.0%29%2A%28fahr-32%29%29%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
