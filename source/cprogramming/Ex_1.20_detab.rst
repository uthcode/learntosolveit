=============
Exercise 1.20
=============

Question
--------


Write a program detab that replaces tabs in the input with the proper number of
blanks to space to the next tab stop. Assume a fixed set of tab stops, say every
n columns. Should n be a variable or a symbolic parameter?

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.20_detab.c
   :language: c
   :tab-width: 2

Explaination
------------

We declare TABINC as 8 in #define TABINC 8 as the number of spaces which make a TAB.
We declare two variables nb for number of spaces and pos for number of tabs.
We get the current character by calling getchar() and storing it in variable c and keep track of the position.
As soon as a space character is found, we increment the number of spaces or number of tabs. We increment the spaces by pos, if the space is not divisible by TABINC. If the space occurance is divisible by TABINC, we increment the number of tabs. This step collects the minimum number of tabs and blanks.
In the else part, when non space is found, we first print the all remaining tabs, then remaining spaces, then print the character. And We reset the position accordingly. If it is a newline, we reset the pos, if it is a tab character, we reset it to previous tab character - This step replaces the spaces with minimum tabs and spaces.


---- 

This document was updated on |today|
