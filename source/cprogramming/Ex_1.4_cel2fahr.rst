====================================
Exercise 1.4 - Temperature Convertor
====================================

Question
--------


Write a program to print the corresponding Celsius to Fahrenheit table.


Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.4_cel2fahr.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_1.4_cel2fahr.c
   :language: c
   :codesite: ideone


Explaination
------------

In the previous exercise we converted Fahrenheit temperature to Celsius
temperature. In this program we are going to convert a given Celsius temperature
to Fahrenheit temperature using the formula C=(5/9)(F-32) To do this we declare
some variables in the beginning of the program so that they can be used in the
later stages of the program. The variables in this program are:
lower,upper,step, celsius,fahr. The variable lower is assigned the value 0
similarly upper to 300, step to 20, and Celsius to lower. So when the program
enters the while loop it checks whether celsius <= upper is true if it is true
then it assigns the variable fahr (9.0/5.0) * celsius + 32.0 and then it prints
out put.

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_1.4_cel2fahr.c`
   * :c-better-explain:`Ex_1.4_cel2fahr.rst`

