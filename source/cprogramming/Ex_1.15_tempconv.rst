=============
Exercise 1.15
=============

Question
--------


Rewrite the temperature conversion program of Section 1.2 to use a function for
conversion.

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.15_tempconv.c
   :language: c
   :tab-width: 2

Explaination
------------

In this program we are going to convert a given Fahrenheit temperature to
Celsius or Celsius temperature to Fahrenheit temperature using the formula
C=(5/9)(F-32). We define some some symbolic constants in the beginning of the
program so that they can be used in the later stages of the program.  The
constants that are defined in the program are: LOWER,UPPER,STEP, . The label
LOWER is assigned the value 0 similarly UPPER to 300, STEP to 20. So when the
program enters the for loop it checks whether fahr <= UPPER, and the increments
fahr using STEP in each iteration.  The second loop checks whether
celsius=LOWER;celsius<=UPPER;celsius=celsius+STEP in each iteration. The program
also contains functions such as fahrtocelsius and celsiustofhar.  The functions
fahrtocelsius and celsiustofhar are used to make the program more dynamic by
giving choices to the users for conversion between 1 - Fahrenheit to Celsius
Conversion 2 - Celsius to Fahrenheit Converion.

---- 

This document was updated on |today|
