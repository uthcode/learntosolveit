=============================================
Section 4.2 - atof - convert string to double
=============================================

Program
=======


.. literalinclude:: ../../languages/cprogs/sec_4.2.c
   :language: c
   :tab-width: 4
   

.. runcode:: ../../languages/cprogs/sec_4.2.c
   :language: c
   :codesite: ideone


Explaination
============

In this program, we do the float conversion, by capturing the entire input as
decimal first, following the same procedure as converting `atoi`, that is we
keep track of sign, get each character and multiply it's positional value by 10
and store the output in a variable called `val`.

Additionally, since it is float, after the decimal, for each decimal we store
the power value too as multiples of 10. For e.g 10.21 will be gotten as value =
1021 and power = 100, So that when we return, we can send as `1021/100`. We
multiply the final by the stored `sign` and return the result.

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`sec_4.2.c`
   * :c-better-explain:`sec_4.2.rst`
