========================
1.1 testing hello, world
========================

Question
========

Run the `hello, world` program on your system. Experiment with leaving out
parts of the program, to see what error messages you get.

.. coderun:: cprogs/sec_1.1_helloworld.c
   :language: c

Explanation
===========

1. Leaving out `#include<stdio.h>`

The program still compiles and it gives the warning stating that it is using a
built-in function printf.

::

    helloworld.c:5: warning: incompatible implicit declaration of built-in function ‘printf’


2. Leaving out `int` or `void` or *both*

The program compiles and runs without any warning.
We know that spaces and indentation is not important, so we can strip them out.

3. The smallest program that compiles **with warning**, but executes is this.

::

    main(){printf("hello,world\n");}

4. Any part of the string "hello,world\n" can be left out without any error,
   just the program output will be different.

5. Leaving any other part the program will now result in **compilation error.**

For e.g. After removing **;** in the above program, we got the compilation
error.

::

    error: expected `;` before the '}' token

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20your%20first%20C%20program%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28%29%20%7B%0A%20%20%20%20printf%28%22hello%2C%20world%5Cn%22%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
