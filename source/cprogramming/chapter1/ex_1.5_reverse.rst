====================================
1.5 Temperature Convertor in Reverse
====================================

Question
--------


Modify the temperature conversion program to print the table in reverse order,
that is, from 300 degrees to 0.

Solution
--------

.. coderun:: cprogs/ex_1.5_reverse.c
   :language: c

Explanation
===========

In the previous exercise we converted Fahrenheit temperature to Celsius
temperature.  In this program we are going to print the table in reverse order,
that is, from 300 degrees to 0. To do this we declare some variables in the
beginning of the program so that they can be used in the later stages of the
program. The variables in this program are: lower,upper,step, celsius,fahr. The
variable lower is assigned the value 0 similarly upper to 300, step to 20, and
Celsius to lower. So when the program enters the while loop it checks whether
celsius <= upper is true if it is true then it assigns the variable fahr
(9.0/5.0) * celsius + 32.0 and then it prints out put.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20reverse%20order%20temperature%20table%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20float%20celsius%3B%0A%20%20%20%20printf%28%22C%20%20%20%20%20F%5Cn%5Cn%22%29%3B%0A%20%20%20%20for%20%28celsius%20%3D%2040%3B%20celsius%20%3E%3D%200%3B%20celsius%20-%3D%2020%29%0A%20%20%20%20%20%20%20%20printf%28%22%253.0f%20%256.1f%5Cn%22%2C%20celsius%2C%20%289.0%2F5.0%29%2Acelsius%20%2B%2032.0%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
