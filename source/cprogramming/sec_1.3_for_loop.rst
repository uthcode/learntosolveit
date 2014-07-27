=============================
Section 1.3 The for statement
=============================


Question
========

There are plenty of different ways to write a program for a particular task.
Let's try a variation on the temperature converter using for loop.


Program
=======

.. literalinclude:: ../../languages/cprogs/sec_1.3_for_loop.c
   :language: c
   :tab-width: 4


.. runcode:: ../../languages/cprogs/sec_1.3_for_loop.c
   :language: c
   :codesite: ideone

Explanation
===========

In this program we are going to convert a given Fahrenheit temperature to
Celsius temperature using the formula C=(5/9)(F-32) using a for loop ::

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
            printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`sec_1.3_for_loop.c`
   * :c-better-explain:`sec_1.3_for_loop.rst`
