=====================================
1.23 Remove comments from a C program
=====================================

Question
--------


Write a program to remove all comments from a C program. Don't forget to handle
quoted strings and character constants properly. C comments don't nest.


Solution
--------

.. literalinclude:: cprogs/ex_1.23_remcomments.c
   :language: c

Explanation
===========

If two subsequent characters start with `/` and `*`, we say we are in-comment,
If we find two characters which are `/` and `/`, we will print the first
character and start treating the second `/` as the possible start of comment. In
the same manner, if we encouter a single quote or a double quote character, then
we understand we are inside a quoted string, so we putchar everything before we
find the matching character again. Within a quoted string, if we encouter a
special character, then we try to read them literally as two characters and
print them.

If / is followed by any other character, we simply print them.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20two-state%20machine%20skips%20%2F%2A%20...%20%2A%2F%20comment%20text%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22a%2F%2Ab%2A%2Fc%22%3B%0A%20%20%20%20int%20i%20%3D%200%2C%20c%2C%20in_comment%20%3D%200%3B%0A%20%20%20%20while%20%28%28c%20%3D%20%28unsigned%20char%29s%5Bi%2B%2B%5D%29%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28%21in_comment%20%26%26%20c%20%3D%3D%20%27%2F%27%20%26%26%20s%5Bi%5D%20%3D%3D%20%27%2A%27%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20in_comment%20%3D%201%3B%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20if%20%28in_comment%20%26%26%20c%20%3D%3D%20%27%2A%27%20%26%26%20s%5Bi%5D%20%3D%3D%20%27%2F%27%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20in_comment%20%3D%200%3B%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20if%20%28%21in_comment%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20putchar%28c%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20putchar%28%27%5Cn%27%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
