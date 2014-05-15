======================================================================
Exercise 3.1 - Binsearch function, writing minimum tests inside a loop
======================================================================

Question
========

Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the
loop and measure the difference in runtime.

.. literalinclude:: ../../languages/cprogs/Ex_3.1_binsearch-2.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_3.1_binsearch-2.c
   :language: c
   :codesite: ideone

Explanation
============

 The program demonstrates a binsearch function which 
 takes element (x) to search for, an array of integers and the length of the array as arguments.
 
 The program determines the position of the element(x) by doing a binary search. Binary search can only
 be used for sorted arrays. Program compares search element (x) with mid element of the given array. If mid element is greater than search 
 element then search continues among the rest of the elements towards left of current mid element. 
 Search continues in similar fashion. If found, program returns the position of search element in the array.
 
 In the example above search element is 9. Program returns 4 which is the position of search element 
 in the given array. 

.. seealso::

   * :c-suggest-improve:`Ex_3.1_binsearch-2.c`
   * :c-better-explain:`Ex_3.1_binsearch-2.rst`
