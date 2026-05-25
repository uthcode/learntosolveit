===================
1.5.3 Line Counting
===================

Program
=======

.. coderun:: cprogs/sec_1.5.3_line_counting.c
   :language: c

Explanation
===========

This Program counts input lines. The program does that counting by setting a
variable nl to 0 in the beginning.  As the program one character at a time in
the while loop  ((c = getchar()) != EOF) till the EOF.  If the character is
newline character '\n' the number of lines variable is incremented, ++nl. At the
end, the number of lines, nl, is printed.

----

This document was updated on |today|

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20count%20newlines%20in%20a%20string%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22a%5Cnb%5Cn%22%3B%0A%20%20%20%20int%20nl%20%3D%200%2C%20i%20%3D%200%3B%0A%20%20%20%20while%20%28s%5Bi%5D%29%20%7B%20if%20%28s%5Bi%5D%20%3D%3D%20%27%5Cn%27%29%20%2B%2Bnl%3B%20i%2B%2B%3B%20%7D%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20nl%29%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
