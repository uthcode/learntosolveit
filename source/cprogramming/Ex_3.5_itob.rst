==============================================================
Exercise 3.5 - function itob, converts a integer into a string
==============================================================

Question
========

Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s
as a hexadecimal integer in s.

.. literalinclude:: ../../languages/cprogs/Ex_3.5_itob.c
   :language: c
   :tab-width: 4

   :language: c

Explanation
===========


In this, we are specifically targetting the conversion to base 16, though we
should be able to extend the program to any base.

As before we get the number and store it in sign, then we get the remainder of
the number after dividing by base `b`.  We covert the number we have gotten to
hexadecimal by this expression ` (j <= 9)?j+'0':j+'a'-10`, which states that if
the number is less than 10, return the string representation of it, otherwise
subtract 10 from it and add 'a' to get the hexadecimal representation of 10 to
15 that (a,b,c,d,e,f).

We store these in a string and it number was a negative number, we append '-'
sign to it. We get the result, by reversing the string which we constructed.



.. seealso::

   * :c-suggest-improve:`Ex_3.5_itob.c`
   * :c-better-explain:`Ex_3.5_itob.rst`
