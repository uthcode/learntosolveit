===========================
Section 1.5.3 Line Counting
===========================

Program
=======

.. literalinclude:: ../../languages/cprogs/sec_1.5.3_line_counting.c
   :language: c
   :tab-width: 4


Explaination
============

This Program counts input lines. 
The program does the counting by setting n1 to 0 in the beginning. As the program enters while loop condition ((c = getchar()) != EOF).  The body of the while now consists of an if, which in turn controls the increment ++nl. The if statement tests the parenthesized condition, and if the condition is true, executes the statements that follows thus printing the number of lines present in the input after the new-line.

---- 

This document was updated on |today|
