================================================
1.9 Replace Continous blanks with a single blank
================================================

Question
--------


Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.

Solution
--------

.. literalinclude:: cprogs/ex_1.9_sinblank.c
   :language: c

Explanation
===========

The essence of this program is, while reading the characters, if the last
character that we encoutered is a blank, then we skip printing it.

::

    if(lastc!=' ')
        putchar(c);

This means that if the last character is not a blank, *only* then print it. We
store the last character in the lastc variable in the line `lastc = c`. For rest
of the characters we simplying print it by `putchar (c)`.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20lastc%20state%20collapses%20multiple%20blanks%20into%20one%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22a%20%20b%20%20%20c%22%3B%0A%20%20%20%20int%20i%20%3D%200%2C%20c%2C%20lastc%20%3D%200%3B%0A%20%20%20%20while%20%28%28c%20%3D%20%28unsigned%20char%29s%5Bi%2B%2B%5D%29%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28c%20%21%3D%20%27%20%27%20%7C%7C%20lastc%20%21%3D%20%27%20%27%29%0A%20%20%20%20%20%20%20%20%20%20%20%20putchar%28c%29%3B%0A%20%20%20%20%20%20%20%20lastc%20%3D%20c%3B%0A%20%20%20%20%7D%0A%20%20%20%20putchar%28%27%5Cn%27%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
