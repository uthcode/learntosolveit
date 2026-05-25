==============================================
1.17 Print lines that are longer than 80 chars
==============================================

Question
--------


Write a program to print all input lines that are longer than 80 characters.

Solution
--------

.. coderun:: cprogs/ex_1.17_lengt80.c
   :language: c

Explanation
===========

A string in C is a character array which ends in ``\0``. getline is a function in
our program, which reads one character at a time using getchar and stores it in
a character array called s[] and it returns the length of the array.

When an array is sent as argument to the function, like ``line[MAXLINE]`` is sent
to ``getline`` function, the value is passed by reference, which means that any
changes the function makes will be available to the main program.

``getline`` returns the length of the line and in our main program, if the length
is greater than 80 characters we print it.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20print%20only%20strings%20longer%20than%20a%20limit%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20%2Alines%5B2%5D%20%3D%20%7B%22hi%22%2C%20%22hello%22%7D%3B%0A%20%20%20%20int%20limit%20%3D%204%2C%20i%2C%20len%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%202%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20%20%20%20%20len%20%3D%200%3B%0A%20%20%20%20%20%20%20%20while%20%28lines%5Bi%5D%5Blen%5D%29%20len%2B%2B%3B%0A%20%20%20%20%20%20%20%20if%20%28len%20%3E%20limit%29%20printf%28%22%25s%5Cn%22%2C%20lines%5Bi%5D%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
