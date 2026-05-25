==============================
1.5 Character Input and Output
==============================

Program
-------

.. coderun:: cprogs/sec_1.5_inp2ou.c
   :language: c


Explanation
-----------

Input : In any programming language input means to feed some data into program.
This can be given in the form of file or from command line. C programming
language provides a set of built-in functions to read given input and feed it to
the program as per requirement.  In this program getchar is a function of
reading the input from the user character by character.

Output : In any programming language output means to display some data on
screen, printer or in any file. C programming language provides a set of built-
in functions to output required data.  Similarly putchar is a function which
gives the output.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20copy%20characters%20from%20a%20string%20to%20output%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22hi%5Cn%22%3B%0A%20%20%20%20int%20i%20%3D%200%3B%0A%20%20%20%20while%20%28s%5Bi%5D%29%20%7B%20putchar%28s%5Bi%5D%29%3B%20i%2B%2B%3B%20%7D%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
