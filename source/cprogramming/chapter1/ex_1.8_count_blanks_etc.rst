==============================================
Exercise 1.8 - Count blanks, tabs and newlines
==============================================

Question
--------

Write a program to count blanks, tabs, and newlines.

Solution
--------

.. literalinclude:: cprogs/ex_1.8_count_blanks_etc.c
   :language: c

Explanation
===========

In this program we are going to count the number of Blanks, tabs and new lines
present in the input.  To do this the program, while reading the characters
checks for the condition c = getchar !=EOF which means if the character is not
end of file continue counting Blanks tabs and newlines. Example input:

I like programming
In C
And the out put shall be:
Blanks: 4
Tabs: 0
Newlines: 1

