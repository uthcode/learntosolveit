================================================
Section 1.2 Variables and Arithmetic Expressions
================================================


Question
========

This program uses the formula `C=(5/9)(F-32)` to print the Fahrenheit temperatures and 
their centigrade or Celsius equivalents


Program
=======

.. literalinclude:: ../../languages/cprogs/sec_1.2_fahr2cel.c
   :language: c
   :tab-width: 4


Explaination
============

In this program we are going to convert a given Fahrenheit temperature to Celsius temperature using the formula C=(5/9)(F-32)
To do this we declare some variables in the beginning of the program so that they can be used in the later stages of the program.
The variables in this program are: lower,upper,step, celsius,fahr.
The variable lower is assigned the value 0 similarly upper to 300, step to 20, and fahr to lower.
So when the program enters the while loop it checks whether fahr <= upper is true if it is true then it assigns the variable celsius 5 * (fahr - 32) / 9 and then it prints out put.

---- 

This document was updated on |today|
