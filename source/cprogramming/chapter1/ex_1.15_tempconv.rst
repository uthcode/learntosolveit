==============================================
1.15 Temperature Convertor using function call
==============================================

Question
--------


Rewrite the temperature conversion program of Section 1.2 to use a function for
conversion.

Solution
--------

.. coderun:: cprogs/ex_1.15_tempconv.c
   :language: c

Explanation
===========


In this program we are going to convert a given Fahrenheit temperature to
Celsius or Celsius temperature to Fahrenheit temperature using the formula
C=(5/9)(F-32 ).  We retain most of the program from section 1.4.  In addition
This program contains functions such as fahrtocelsius and celsiustofhar. The
functions fahr_to_celsius and celsiustofhar are used to make the program more
dynamic by giving choices to the users for conversion between 1 - Fahrenheit to
Celsius Conversion 2 - Celsius to Fahrenheit Converion.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20function%20dispatch%20for%20temperature%20conversion%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23define%20LOWER%200%0A%23define%20UPPER%2040%0A%23define%20STEP%2020%0Avoid%20fahr_to_celsius%28void%29%3B%0Aint%20main%28void%29%20%7B%0A%20%20%20%20printf%28%22Fahrenheit%20to%20Celsius%3A%5Cn%22%29%3B%0A%20%20%20%20fahr_to_celsius%28%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0Avoid%20fahr_to_celsius%28%29%20%7B%0A%20%20%20%20float%20fahr%3B%0A%20%20%20%20for%20%28fahr%20%3D%20LOWER%3B%20fahr%20%3C%3D%20UPPER%3B%20fahr%20%2B%3D%20STEP%29%0A%20%20%20%20%20%20%20%20printf%28%22%253.0f%20%256.1f%5Cn%22%2C%20fahr%2C%20%285.0%2F9.0%29%2A%28fahr-32.0%29%29%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
