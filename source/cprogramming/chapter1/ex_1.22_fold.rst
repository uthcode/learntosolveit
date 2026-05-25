====================
1.22 fold long lines
====================

Question
--------


Write a program to ``fold`` long input lines into two or more shorter lines
after the last non-blank character that occurs before the n-th column of input.
Make sure your program does something ntelligent with very long lines, and if
there are no blanks or tabs before the specified column.


Solution
--------

.. coderun:: cprogs/ex_1.22_fold.c
   :language: c

Explanation
===========

1. We determine the column to fold in the MAXCOL variable.

2. Since tab character can occur too and folding a tab character means folding
it in mid-way, we also replace the tabs in the line with spaces.

3. Every character of the file is filled into a ``line[MAXCOL]`` array and that
line is acted upon by the program.

4. We start at ``pos=0`` and take each character and place it in ``line[pos]`` and
then we analyze the character to act upon the condition.

6. If the character is ``\t``. We go and expand the tab character in the
``line[pos]`` and get newposition. So, when line[\t] at pos = 0, it will be now
``line[' ', ' ', ' ',' ',' ',' ',' ',' '] and pos = 8``

7. If character is ``\n`` then we print the entire line contents reset the ``pos``
back to 0.

8. *otherwise*, we get into our program.

When we are folding, we should not be folding in between the word. So we have to
track the previous space occuring in a line. The logic follows.

1. When our position is greater than MAXCOL, then we look for previous blank
space by using ``getblank`` and we get the position of that blank.

2. We then ``fold``, getblank will return the pos which is not greater than
MAXCOL. So, the print the characters we have in line and then print newline.

3. We determine the new position based the return value of getblank. If the
return value of getblank was greater than MAXCOL, then our new position is 0,
which is  a newline. We will replace the contents of line starting from 0, mark
this as ``i``, and place the folded contents by the last ``for loop`` in the program
and after placing the folded contents we return the new value of ``i``, which is
our updated ``pos``.

With our new position we continue with the rest of the program.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20fold%20long%20line%20at%20word%20boundary%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23define%20MAXCOL%2010%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22hi%20there%20ok%22%3B%0A%20%20%20%20int%20i%20%3D%200%2C%20col%20%3D%200%3B%0A%20%20%20%20while%20%28s%5Bi%5D%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28col%20%3E%3D%20MAXCOL%20%26%26%20s%5Bi%5D%20%3D%3D%20%27%20%27%29%20%7B%20putchar%28%27%5Cn%27%29%3B%20col%20%3D%200%3B%20i%2B%2B%3B%20continue%3B%20%7D%0A%20%20%20%20%20%20%20%20putchar%28s%5Bi%2B%2B%5D%29%3B%0A%20%20%20%20%20%20%20%20col%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20putchar%28%27%5Cn%27%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
