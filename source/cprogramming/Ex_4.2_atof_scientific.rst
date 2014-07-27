========================================================
Exercise 4.2 - Extend atof to handle scientific notation
========================================================

Question
========

Extend atof to handle scientific notation of the form 123.45e-6 where a
floating-point number may be followed by e or E and an optionally signed
exponent.

.. literalinclude:: ../../languages/cprogs/Ex_4.2_atof_scientific.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.2_atof_scientific.c
   :language: c
   :codesite: ideone

Explanation
===========

For the input::

   1.0e10

We might get the output::

   1410065408.000000

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_4.2_atof_scientific.c`
   * :c-better-explain:`Ex_4.2_atof_scientific.rst`
