========================================================
Exercise 4.2 - Extend atof to handle scientific notation
========================================================

Question
========

Exercise 4 - 2. Extend atof to handle scientific notation of the form 123.45e-6
where a floating-point number may be followed by e or E and an optionally
signed exponent.


.. literalinclude:: Ex_4.2_atof_scientific.c
   :language: c

Explanation
===========

For the input::

   1.0e10

We might get the output::

   1410065408.000000


