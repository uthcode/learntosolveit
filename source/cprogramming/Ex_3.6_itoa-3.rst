====================================
Exercise 3.6 - itoa with field width
====================================

Question
========

Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with
blanks on the left if necessary to make it wide enough.

.. literalinclude:: ../../languages/cprogs/Ex_3.6_itoa-3.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_3.6_itoa-3.c
   :language: c
   :codesite: ideone

Explanation
===========

Note: For negative numbers the negative sign is written close to the number
instead of before the padded width. This is ``itoa`` conversion with padding. We
specify the width of the number we want in ``w`` and as before, we proceed with
``itoa``, wherein extract the unit digit (n ``% 10``), convert it to character and
store it in a character array. If it were a negative number we store the sign
too. We keep track of number of digits in the number in a variable, ``i`` and for
the remaining digits, for ``i < w``, we append the space character " ".

We reverse the string thus constructed for our result.


Run It
======

.. raw:: html

   <iframe frameborder="0" width="100%" height="500px" src="https://replit.com/@learntosolveit/ex36itoa-3?embed=true"></iframe>



.. seealso::

   * :c-suggest-improve:`Ex_3.6_itoa-3.c`
   * :c-better-explain:`Ex_3.6_itoa-3.rst`
