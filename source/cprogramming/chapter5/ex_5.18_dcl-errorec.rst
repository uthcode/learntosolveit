==============================
5.18 recover from input errors
==============================

Question
========

Make dcl recover from input errors.

.. literalinclude:: cprogs/ex_5.18_dcl-errorec.c
   :language: c
   :tab-width: 4

Explanation
===========

This program is a recursive descent parser that converts C-style declarations into English descriptions.
The program takes a C declaration as input and converts it into a more readable English description. For example:

::

    ./ex_5.18_dcl-errorec
    char *str[]
    str  arg[] of pointer to char


The program has an errmsg function that is called whenever an error is detected during parsing.
The dcl and dirdcl functions, which are responsible for parsing the declarator, continue parsing even if an error is encountered.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20DCL%20output%20%E2%80%94%20combine%20name%2C%20modifier%2C%20and%20datatype%20strings%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20%2F%2A%20Simulates%20parsing%20%22int%20%2Ap%22%20%E2%86%92%20name%3D%22p%22%2C%20out%3D%22%20pointer%20to%22%2C%20datatype%3D%22int%22%20%2A%2F%0A%20%20%20%20char%20datatype%5B%5D%20%3D%20%22int%22%3B%0A%20%20%20%20char%20name%5B%5D%20%20%20%20%20%3D%20%22p%22%3B%0A%20%20%20%20char%20out%5B%5D%20%20%20%20%20%20%3D%20%22%20pointer%20to%22%3B%0A%20%20%20%20printf%28%22%25s%25s%20%25s%5Cn%22%2C%20name%2C%20out%2C%20datatype%29%3B%0A%20%20%20%20%2F%2A%20Simulates%20parsing%20%22char%20%28%2Afp%29%28%29%22%20%2A%2F%0A%20%20%20%20printf%28%22%25s%25s%20%25s%5Cn%22%2C%20%22fp%22%2C%20%22%20pointer%20to%20function%20returning%22%2C%20%22char%22%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
