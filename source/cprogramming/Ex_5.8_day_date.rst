==============================================================
Exercise 5.8 - program which has day of the year and month day
==============================================================

Question
========

There is no error checking in day_of_year or month_day. Remedy this defect.

.. literalinclude:: ../../languages/cprogs/Ex_5.8_day_date.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_5.8_day_date.c
   :language: c
   :codesite: ideone

Explaination
============

Given a calendar date, we will determine how many days from the start of the
year is that date; we will also do the reverse, wherein give the days from the
start of the year, which date and month does it fall.

We define the function `int day_of_year(int year,int month,int day)` which takes
the calendar date details like year, month and day.  Using the year, it
determines if it is leap year. A year is a leap year, if it divisible by 4 and
but not by 100, except when it is divisible by 400. If it is leap year, we use
29 days in feb, otherwise it is 28. We store the number of days each month in a
static array `char daytab`, which we use in our calculations.

In day_of_year, we add the days in eac month till our current month and then add
remain days and return.

In the `month_day` function, we subtract days of each month from the day, till
the day is lesser than days in that month and then print the result that we got
after conversion.

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_5.8_day_date.c`
   * :c-better-explain:`Ex_5.8_day_date.rst`
