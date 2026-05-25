=====================
1.3 The for statement
=====================


Question
========

There are plenty of different ways to write a program for a particular task.
Let's try a variation on the temperature converter using for loop.


Program
=======

.. coderun:: cprogs/sec_1.3_for_loop.c
   :language: c

Explanation
===========

In this program we are going to convert a given Fahrenheit temperature to
Celsius temperature using the formula C=(5/9)(F-32) using a for loop ::

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
            printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20for%20loop%20temperature%20conversion%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28%29%20%7B%0A%20%20%20%20int%20fahr%3B%0A%20%20%20%20for%20%28fahr%20%3D%200%3B%20fahr%20%3C%3D%2040%3B%20fahr%20%3D%20fahr%20%2B%2020%29%0A%20%20%20%20%20%20%20%20printf%28%22%253d%20%256.1f%5Cn%22%2C%20fahr%2C%20%285.0%2F9.0%29%2A%28fahr-32%29%29%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
