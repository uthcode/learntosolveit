==============================================
1.16 Print length of arbitrary long input line
==============================================

Question
--------


Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text.

Solution
--------

.. coderun:: cprogs/ex_1.16_longline.c
   :language: c


Explanation
===========

A string in C is a character array which ends in `\0`. getline is a function in
our program, which reads one character at a time using getchar and stores it in
a character array called s[] and it returns the length of the array.

We keep track of each line and it's length using a variable, `max`. If the
length of the line is greater than `max`, then we copy that line into the
`maxline` using a copy routine.

At the end of the program, whichever was the longest line that was copied in
maxline array, we just print that.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20find%20and%20report%20the%20longest%20of%20two%20strings%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Avoid%20copy%28char%20to%5B%5D%2C%20const%20char%20from%5B%5D%29%3B%0Aint%20main%28%29%20%7B%0A%20%20%20%20char%20%2Alines%5B2%5D%20%3D%20%7B%22hi%22%2C%20%22hello%22%7D%3B%0A%20%20%20%20char%20longest%5B10%5D%3B%0A%20%20%20%20int%20max%20%3D%200%2C%20i%2C%20len%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%202%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20%20%20%20%20len%20%3D%200%3B%0A%20%20%20%20%20%20%20%20while%20%28lines%5Bi%5D%5Blen%5D%29%20len%2B%2B%3B%0A%20%20%20%20%20%20%20%20if%20%28len%20%3E%20max%29%20%7B%20max%20%3D%20len%3B%20copy%28longest%2C%20lines%5Bi%5D%29%3B%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22length%20%3D%20%25d%2C%20string%3D%25s%5Cn%22%2C%20max%2C%20longest%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0Avoid%20copy%28char%20to%5B%5D%2C%20const%20char%20from%5B%5D%29%20%7B%0A%20%20%20%20int%20i%20%3D%200%3B%0A%20%20%20%20while%20%28%28to%5Bi%5D%20%3D%20from%5Bi%5D%29%20%21%3D%20%27%5C0%27%29%20%2B%2Bi%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
