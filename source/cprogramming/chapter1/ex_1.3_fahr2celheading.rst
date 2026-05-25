=========================
1.3 Temperature Convertor
=========================

Question
--------


Modify the temperature conversion program to print a heading above the table.

Solution
--------

.. coderun:: cprogs/ex_1.3_fahr2celheading.c
   :language: c

Explanation
-----------

In this program we are going to convert a given Fahrenheit temperature to
Celsius temperature using the formula C=(5/9)(F-32) To do this we declare some
variables in the beginning of the program so that they can be used in the later
stages of the program. The variables in this program are: lower,upper,step,
celsius,fahr. The variable lower is assigned the value 0 similarly upper to
300, step to 20, and fahr to lower. So when the program enters the while loop
it checks whether fahr <= upper is true, if it is true then it assigns the
variable celsius 5 * (fahr - 32) / 9 and then it prints output.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20temperature%20table%20with%20header%20row%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20float%20fahr%2C%20celsius%3B%0A%20%20%20%20printf%28%22Fahr%5CtCelsius%5Cn%22%29%3B%0A%20%20%20%20for%20%28fahr%20%3D%200%3B%20fahr%20%3C%3D%2040%3B%20fahr%20%2B%3D%2020%29%20%7B%0A%20%20%20%20%20%20%20%20celsius%20%3D%20%285.0%2F9.0%29%20%2A%20%28fahr%20-%2032.0%29%3B%0A%20%20%20%20%20%20%20%20printf%28%22%254.0f%20%2510.1f%5Cn%22%2C%20fahr%2C%20celsius%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
