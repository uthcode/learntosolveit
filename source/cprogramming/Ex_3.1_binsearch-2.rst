======================================================================
Exercise 3.1 - Binary search function, writing minimum tests inside a loop
======================================================================

Question
========

Our binary search makes two tests inside the loop, when one would suffice (at the price of
more tests outside.) Write a version with only one test inside the loop and measure the difference in runtime.

.. literalinclude:: ../../languages/cprogs/Ex_3.1_binsearch-2.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_3.1_binsearch-2.c
   :language: c
   :codesite: ideone

Explanation
============

The program returns the position of element 9 in the defined array which is 4.

Note that binary search works only with sorted array.

Program compares 9 with mid element of the given array. If mid element is greater than 9 then search continues 
among the rest of the elements towards left of current mid element. Search continues in similar fashion. If found,
program returns the position of 9 in the array.


.. seealso::

   * :c-suggest-improve:`Ex_3.1_binsearch-2.c`
   * :c-better-explain:`Ex_3.1_binsearch-2.rst`
