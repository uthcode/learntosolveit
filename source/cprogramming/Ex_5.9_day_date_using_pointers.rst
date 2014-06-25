=============================================================================
Exercise 5.9 - program which has day of the year and month day using pointers
=============================================================================

Question
========

Rewrite the routines day_of_year and month_day with pointers instead of
indexing.

.. literalinclude:: ../../languages/cprogs/Ex_5.9_day_date_using_pointers.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_5.9_day_date_using_pointers.c
   :language: c
   :codesite: ideone

Explaination
============

This program is same as the previous program Exercise 5.8 and we calculate the
day of the year as before and return it to be printed in the main function.

In the month_day, we send two additional pointers `int *pmonth,int *pday` and
after calculating the number of months and days, we return it using the pointers
itself to the main function instead of printing them in the function.

.. git-changelog::

.. seealso::

   * :c-suggest-improve:`Ex_5.9_day_date_using_pointers.c`
   * :c-better-explain:`Ex_5.9_day_date_using_pointers.rst`
