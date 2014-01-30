=============
Exercise 1.12
=============

Question
--------


Write a program that prints its input one word per line.

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.12_word_per_line.c
   :language: c
   :tab-width: 2

Explaination
------------

This Program counts words per lines. The program does the counting by setting c to getchar in the beginning. As the program enters while loop condition c != EOF The body of the while consists of an if, which in turn controls c == ' ') { putchar('\n')The if statement tests the parenthesized condition, and if the condition is true, executes the statements that follows thus printing the number of words present in the input after the new-line.

---- 

This document was updated on |today|
