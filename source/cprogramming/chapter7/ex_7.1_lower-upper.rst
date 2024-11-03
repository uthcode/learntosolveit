=========================================================
Exercise 7.1 - upper case to lower or lower case to upper
=========================================================

Question
========

Write a program that converts upper case to lower or lower case to upper,
depending on the name it is invoked with, as found in argv[0]

.. literalinclude:: cprogs/ex_7.1_lower-upper.c
   :language: c
   :tab-width: 4

Explanation
===========

This program converts the input string to either lower case or upper case depending on the program.
This takes help of the various header files like.

::

    #include <ctype.h>   // Provides character handling functions like tolower() and toupper()
    #include <stdio.h>   // Provides input/output functions like putchar()
    #include <string.h>  // Provides string handling functions like strcmp()



Visualize
=========

.. raw:: html

    <iframe width="100%" height="800px" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=/*%20Write%20a%20program%20which%20converts%20upper%20case%20to%20lower%20case%20or%20lower%20case%20to%0Aupper%20case%20depending%20on%20the%20name%20it%20is%20involved%20with%20as%20found%20in%20argv%5B0%5D%20*/%0A%0A%23include%20%3Cctype.h%3E%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0A%0A/*%20lower%3A%20converts%20upper%20case%20to%20lower%20case%20*/%0A/*%20upper%3A%20converts%20lower%20case%20to%20upper%20case%20*/%0A%0Aconst%20char%20*input%20%3D%20%22This%5Ctis%5Cta%5Cttest%22%3B%0Aint%20input_index%20%3D%200%3B%0A%0Aint%20_getchar%28void%29%20%7B%0A%20%20%20%20if%20%28input%5Binput_index%5D%20%3D%3D%20'%5C0'%29%20%7B%0A%20%20%20%20%20%20%20%20return%20EOF%3B%0A%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20return%20input%5Binput_index%2B%2B%5D%3B%0A%20%20%20%20%7D%0A%7D%0A%0A%0A%0Aint%20main%28int%20argc,%20char%20*argv%5B%5D%29%20%7B%0A%20%20%20%20int%20c%3B%0A%0A%20%20%20%20if%20%28strcmp%28argv%5B0%5D,%20%22./lower%22%29%20%3D%3D%200%29%0A%20%20%20%20%20%20%20%20while%20%28%28c%20%3D%20_getchar%28%29%29%20!%3D%20EOF%29%0A%20%20%20%20%20%20%20%20%20%20%20%20putchar%28tolower%28c%29%29%3B%0A%20%20%20%20else%0A%20%20%20%20%20%20%20%20while%20%28%28c%20%3D%20_getchar%28%29%29%20!%3D%20EOF%29%0A%20%20%20%20%20%20%20%20%20%20%20%20putchar%28toupper%28c%29%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>

