===============================================
Exercise 1.5 - Temperature Convertor in Reverse
===============================================

Question
--------


Modify the temperature conversion program to print the table in reverse order,
that is, from 300 degrees to 0.

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.5_reverse.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_1.5_reverse.c
   :language: c
   :codesite: ideone

:c-suggest-improve:`Ex_1.5_reverse.c`


Explaination
------------

In the previous exercise we converted Fahrenheit temperature to Celsius
temperature.  In this program we are going to print the table in reverse order,
that is, from 300 degrees to 0. To do this we declare some variables in the
beginning of the program so that they can be used in the later stages of the
program. The variables in this program are: lower,upper,step, celsius,fahr. The
variable lower is assigned the value 0 similarly upper to 300, step to 20, and
Celsius to lower. So when the program enters the while loop it checks whether
celsius <= upper is true if it is true then it assigns the variable fahr
(9.0/5.0) * celsius + 32.0 and then it prints out put.

:c-better-explain:`Ex_1.5_reverse.rst`

---- 

This document was updated on |today|
