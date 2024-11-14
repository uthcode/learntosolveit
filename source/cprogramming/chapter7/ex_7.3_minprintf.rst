=======================================================
Exercise 7.3 - minprintf to handle facilities of printf
=======================================================

Question
========

Revise minprintf to handle more of the other facilities of printf.

.. literalinclude:: cprogs/ex_7.3_minprintf.c
   :language: c
   :tab-width: 4

Explanation
===========

The header `#include <stdarg.h>` provides functionality for functions with variable arguments (variadic functions) It defines va_list, va_start, va_arg, and va_end macros which are used to handle variable arguments.
Essential for implementing functions like scanf/printf that can take varying numbers of arguments


Visualize
=========

.. raw:: html

    <iframe width="100%" height="800" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=/*%20minprintf%3A%20minimalistic%20printf%20function%20*/%0A%23include%20%3Cstdarg.h%3E%0A%23include%20%3Cstdio.h%3E%0A%0Avoid%20minprintf%28char%20*fmt,%20...%29%3B%0A%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20*a%20%3D%20%22Hello,World%22%3B%0A%20%20%20%20minprintf%28%22%25s%22,%20a%29%3B%0A%20%20%20%20int%20i%20%3D%2010%3B%0A%20%20%20%20minprintf%28%22%25d%5Cn%22,%20i%29%3B%0A%20%20%20%20int%20b%20%3D%20011%3B%0A%20%20%20%20minprintf%28%22b%20in%20octal%3A%20%25o,%20and%20in%20decimal%3A%20%25d%5Cn%22,%20b,%20b%29%3B%0A%20%20%20%20int%20h%20%3D%2010%3B%0A%20%20%20%20minprintf%28%22h%20in%20hex%3A%20%25x,%20and%20in%20decimal%3A%20%25d%5Cn%22,%20h,%20h%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A%0Avoid%20minprintf%28char%20*fmt,%20...%29%20%7B%0A%20%20%20%20va_list%20ap%3B%20/*%20points%20to%20each%20unnamed%20arg%20in%20turn%20*/%0A%20%20%20%20char%20*p,%20*sval%3B%0A%20%20%20%20int%20ival%3B%0A%20%20%20%20double%20dval%3B%0A%0A%20%20%20%20va_start%28ap,%20fmt%29%3B%20/*%20make%20ap%20point%20to%201st%20unnamed%20arg%20*/%0A%0A%20%20%20%20for%20%28p%20%3D%20fmt%3B%20*p%3B%20p%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28*p%20!%3D%20'%25'%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20putchar%28*p%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20continue%3B%0A%20%20%20%20%20%20%20%20%7D%0A%0A%20%20%20%20%20%20%20%20switch%20%28*%2B%2Bp%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20'd'%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20ival%20%3D%20va_arg%28ap,%20int%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22%25d%22,%20ival%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20'f'%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20dval%20%3D%20va_arg%28ap,%20double%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22%25f%22,%20dval%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20's'%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20for%20%28sval%20%3D%20va_arg%28ap,%20char%20*%29%3B%20*sval%3B%20sval%2B%2B%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20putchar%28*sval%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20'o'%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20ival%20%3D%20va_arg%28ap,%20int%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22%25o%22,%20ival%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20'x'%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20ival%20%3D%20va_arg%28ap,%20int%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22%25x%22,%20ival%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20default%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20putchar%28*p%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20va_end%28ap%29%3B%20/*%20clean%20up%20when%20done%20*/%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>


