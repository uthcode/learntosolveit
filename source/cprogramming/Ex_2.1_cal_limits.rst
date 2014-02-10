===============================
Exercise 2.1 - Count the Ranges
===============================

Question
========

Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation.  Harder if you compute them: determine the ranges of the various floating-point types.  


.. literalinclude:: ../../languages/cprogs/Ex_2.1_cal_limits.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_2.1_cal_limits.c
   :language: c
   :codesite: ideone

Explaination
============


The execution of the above program will give::

   Minimum Signed Char -128
   Maximum Signed Char 127
   Minimum Signed Short -32768
   Maximum Signed Short 32767
   Minimum Signed Int -2147483648
   Maximum Signed Int 2147483647
   Minimum Signed Long -2147483648
   Maximum signed Long 2147483647
   Maximum Unsigned Char 255
   Maximum Unsigned Short 65535
   Maximum Unsigned Int 4294967295
   Maximum Unsigned Long 4294967295


.. seealso::

   * :c-suggest-improve:`Ex_2.1_cal_limits.c`
   * :c-better-explain:`Ex_2.1_cal_limits.rst`
