===================================================
5.8 program which has day of the year and month day
===================================================

Question
========

There is no error checking in day_of_year or month_day. Remedy this defect.

.. coderun:: cprogs/ex_5.8_day_date.c
   :language: c
   :tab-width: 4

Explanation
===========

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





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20day_of_year%20using%20a%202D%20month-day%20table%2C%20leap%20year%20handled%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Astatic%20char%20daytab%5B2%5D%5B13%5D%20%3D%20%7B%0A%20%20%20%20%7B0%2C%2031%2C%2028%2C%2031%2C%2030%2C%2031%2C%2030%2C%2031%2C%2031%2C%2030%2C%2031%2C%2030%2C%2031%7D%2C%0A%20%20%20%20%7B0%2C%2031%2C%2029%2C%2031%2C%2030%2C%2031%2C%2030%2C%2031%2C%2031%2C%2030%2C%2031%2C%2030%2C%2031%7D%0A%7D%3B%0Aint%20day_of_year%28int%20year%2C%20int%20month%2C%20int%20day%29%20%7B%0A%20%20%20%20int%20i%2C%20leap%20%3D%20%28year%254%3D%3D0%20%26%26%20year%25100%21%3D0%29%20%7C%7C%20year%25400%3D%3D0%3B%0A%20%20%20%20for%20%28i%20%3D%201%3B%20i%20%3C%20month%3B%20i%2B%2B%29%20day%20%2B%3D%20daytab%5Bleap%5D%5Bi%5D%3B%0A%20%20%20%20return%20day%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20day_of_year%282024%2C%203%2C%201%29%29%3B%20%20%2F%2A%20leap%3A%2031%2B29%2B1%20%3D%2061%20%2A%2F%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20day_of_year%282023%2C%203%2C%201%29%29%3B%20%20%2F%2A%20non-leap%3A%2031%2B28%2B1%20%3D%2060%20%2A%2F%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
