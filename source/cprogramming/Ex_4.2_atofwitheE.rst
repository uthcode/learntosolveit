==============================================================
Exercise 4.2- function converts the string to a floating value
==============================================================

Question
========

Extend atof to handle scientific notation of the form
123.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent.

.. literalinclude:: ../../languages/cprogs/Ex_4.2_atofwitheE.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.2_atofwitheE.c
   :language: c
   :codesite: ideone

Explaination
============

For the input::

   1.0e10

We might get the output::

   1410065408.000000



.. seealso::

   * :c-suggest-improve:`Ex_4.2_atofwitheE.c`
   * :c-better-explain:`Ex_4.2_atofwitheE.rst`
