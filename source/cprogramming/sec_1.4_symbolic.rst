==============================
Section 1.4 Symbolic Constants
==============================

Program
=======

.. literalinclude:: ../../languages/cprogs/sec_1.4_symbolic.c
   :language: c
   :tab-width: 4
   
.. runcode:: ../../languages/cprogs/sec_1.4_symbolic.c
   :language: c
   :codesite: ideone

Explaination
============

In this program we are going to convert a given Fahrenheit temperature to
Celsius temperature using the formula C=(5/9)(F-32). We define some some
**symbolic constants** in the beginning of the program so that they can be used
in the later stages of the program. The constants that are defined in the program are:
LOWER,UPPER,STEP, . The label LOWER is assigned the value 0 similarly UPPER
to 300, STEP to 20. So when the program enters the for loop it checks whether
fahr <= UPPER, and the increments fahr using STEP in each iteration.

*symbolic constants* are substituted inline in the program during pre-processing
phase of compilation.

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`sec_1.4_symbolic.c`
   * :c-better-explain:`sec_1.4_symbolic.rst`
   
---- 

This document was updated on |today|
