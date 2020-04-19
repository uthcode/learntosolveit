================================================
Section 1.2 Variables and Arithmetic Expressions
================================================


Question
========

This program uses the formula `C=(5/9)(F-32)` to print the Fahrenheit
temperatures and  their centigrade or Celsius equivalents.


Program
=======

.. literalinclude:: ../../languages/cprogs/sec_1.2_fahr2cel.c
   :language: c
   :tab-width: 4


.. runcode:: ../../languages/cprogs/sec_1.2_fahr2cel.c
   :language: c
   :codesite: ideone

Explanation
===========

In this program we are going to convert a given Fahrenheit temperature to
Celsius temperature using the formula C=(5/9)(F-32) To do this we declare some
variables in the beginning of the program so that they can be used in the later
stages of the program. The variables in this program are: lower,upper,step,
celsius,fahr.


The variable lower is assigned the value 0 similarly upper to 300, step to 20,
and fahr to lower. So when the program enters the while loop it checks whether
fahr <= upper is true if it is true then it assigns the variable celsius 5 *
(fahr - 32) / 9 and then it prints out put.


Understand
----------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%3Cstdio.h%3E%0A%0A/*%20print%20Fahrenheit-Celsius%20table%20for%20fahr%20%3D%200,20%20...%20300%20*/%0A%0Aint%20main%28%29%0A%7B%0A%20%20%20%20int%20lower,upper,step%3B%0A%20%20%20%20int%20celsius,fahr%3B%0A%0A%20%20%20%20lower%20%3D%200%3B%0A%20%20%20%20upper%20%3D%20300%3B%0A%20%20%20%20step%20%3D%2020%3B%0A%0A%20%20%20%20fahr%20%3D%20lower%3B%0A%0A%20%20%20%20while%28%20fahr%20%3C%3D%20upper%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20celsius%20%3D%20%205%20*%20%28fahr%20-%2032%29%20/%209%3B%0A%20%20%20%20%20%20%20%20printf%28%22%25d%5Ct%25d%5Cn%22,fahr,celsius%29%3B%0A%20%20%20%20%20%20%20%20fahr%20%3D%20fahr%20%2B%20step%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D"> </iframe>


.. seealso::

   * :c-suggest-improve:`sec_1.2_fahr2cel.c`
   * :c-better-explain:`sec_1.2_fahr2cel.rst`
   
---- 

This document was updated on |today|
