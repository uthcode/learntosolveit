===============================
Exercise 1.22 - fold long lines
===============================

Question
--------


Write a program to ``fold'' long input lines into two or more shorter lines
after the last non-blank character that occurs before the n-th column of input.
Make sure your program does something ntelligent with very long lines, and if
there are no blanks or tabs before the specified column.


Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.22_fold.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_1.22_fold.c
   :language: c
   :codesite: ideone

Explaination
------------

1. We determine the column to fold in the MAXCOL variable.

2. Since tab character can occur too and folding a tab character means folding
it in mid-way, we also replace the tabs in the line with spaces.

3. Every character of the file is filled into a `line[MAXCOL]` array and that
line is acted upon by the program.

4. We start at `pos=0` and take each character and place it in `line[pos]` and
then we analyze the character to act upon the condition.

6. If the character is `\t`. We go and expand the tab character in the
`line[pos]` and get newposition. So, when line[\t] at pos = 0, it will be now
`line[' ', ' ', ' ',' ',' ',' ',' ',' '] and pos = 8`

7. If character is `\n` then we print the entire line contents reset the `pos`
back to 0.

8. *otherwise*, we get into our program.

When we are folding, we should not be folding in between the word. So we have to
track the previous space occuring in a line. The logic follows.

1. When our position is greater than MAXCOL, then we look for previous blank
space by using `getblank` and we get the position of that blank.

2. We then `fold`, getblank will return the pos which is not greater than
MAXCOL. So, the print the characters we have in line and then print newline.

3. We determine the new position based the return value of getblank. If the
return value of getblank was greater than MAXCOL, then our new position is 0,
which is  a newline. We will replace the contents of line starting from 0, mark
this as `i`, and place the folded contents by the last `for loop` in the program
and after placing the folded contents we return the new value of `i`, which is
our updated `pos`.

With our new position we continue with the rest of the program.

.. seealso::

   * :c-suggest-improve:`Ex_1.22_fold.c`
   * :c-better-explain:`Ex_1.22_fold.rst`

---- 

This document was updated on |today|
