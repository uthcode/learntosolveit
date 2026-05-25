=========================
1.13 Horizontal Histogram
=========================

Question
--------


Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal.

Solution
--------

.. coderun:: cprogs/ex_1.13_his_horizontal.c
   :language: c

Explanation
===========

We desire the histogram like the following.

If the input is **I love C programming**

The output should be.::

    *
    ****
    *
    ***********

The way it is accomplished in the above program, read each character using
getchar, if it is special character like a space, tab or newline,  go to next
line by printing `\n` otherwise print a `*` character.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20horizontal%20histogram%20%E2%80%94%20print%20%2A%20per%20char%2C%20newline%20at%20word%20boundary%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22hi%5Cn%22%3B%0A%20%20%20%20int%20i%20%3D%200%2C%20c%3B%0A%20%20%20%20while%20%28%28c%20%3D%20%28int%29%28unsigned%20char%29s%5Bi%2B%2B%5D%29%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%20%27%20%7C%7C%20c%20%3D%3D%20%27%5Cn%27%20%7C%7C%20c%20%3D%3D%20%27%5Ct%27%29%20putchar%28%27%5Cn%27%29%3B%0A%20%20%20%20%20%20%20%20else%20putchar%28%27%2A%27%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
