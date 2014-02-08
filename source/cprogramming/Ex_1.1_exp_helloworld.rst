===================================
Exercise 1.1 - testing hello, world
===================================

Question
========

Run the `hello, world` program on your system. Experiment with leaving out parts
of the program, to see what error messages you get.

.. literalinclude:: ../../languages/cprogs/sec_1.1_helloworld.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/sec_1.1_helloworld.c
   :language: c
   :codesite: ideone

Explaination
============

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

4. Any part of the string "hello,world\n" can be left out without any error, just
the program output will be different.

5. Leaving any other part the program will now result in **compilation error.**

For e.g. After removing **;** in the above program, we got the compilation error.

::

    error: expected `;` before the '}' token

.. seealso::

   * :c-suggest-improve:`sec_1.1_helloworld.c`
   * :c-better-explain:`Ex_1.1_exp_helloworld.rst`

