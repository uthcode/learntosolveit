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

In this program we are going to convert a given Fahrenheit temperature to Celsius or Celsius temperature to Fahrenheit temperature using the formula C=(5/9)(F-32 ).  We retain most of the program from section 1.4.  In addition This program contains functions such as fahrtocelsius and celsiustofhar. The functions fahrtocelsius and celsiustofhar are used to make the program more dynamic by giving choices to the users for conversion between 1 - Fahrenheit to Celsius Conversion 2 - Celsius to Fahrenheit Converion.

---- 

This document was updated on |today|
