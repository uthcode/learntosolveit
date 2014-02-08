==================
Section 1.6 Arrays
==================


Program
=======

.. literalinclude:: ../../languages/cprogs/sec_1.6_arrays.c
   :language: c
   :tab-width: 4
 
.. runcode:: ../../languages/cprogs/sec_1.6_arrays.c
   :language: c
   :codesite: ideone

Explaination
============

This section introduces arrays. Arrays in C hold a number of same typed
variables into a one entity and are indexed by their position. In this program
it is demonstrated by holding the count of number of digits in the array `int
ndigit[10];`  This program lets us count the digits, whitespace and others.
There are 10 digits, ranging from 0 to 9, so we create a array, ndigits which
can hold 10 digits. In the program we getchar() and for characters between '0'
and '9', we take it and substract '0' from it so that we can get the value and
we increment array index at that value.

In the end, we print the values stored in the array.


.. seealso::

   * :c-suggest-improve:`sec_1.6_arrays.c`
   * :c-better-explain:`sec_1.6_arrays.rst`

