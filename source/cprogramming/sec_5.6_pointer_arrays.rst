===============================
Section 5.6 - Pointer to Arrays
===============================

Let us a write a program that will sort a set of text lines in alphabetical
order, a stripped down version of unix sort program.


.. literalinclude:: ../../languages/cprogs/sec_5.6_pointer_arrays.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/sec_5.6_pointer_arrays.c
   :language: c
   :codesite: ideone

Explaination
============

In this program, Pointer to Arrays, we intend to a sort a list of lines which is
sent to the program as `char *lineptr[MAXLINES]`. The sort function uses a quick
sort procedure.

If the lines are not sorted for the pointers, left and right, it starts by
swaping the left end with the middle::

	swap(v,left,(left+right)/2);

We assign left to last, and consider last as the pivot element. We sort in
ascending order the string from , the strings from left to pivot element, last
and then we recursively qsort(v, left, last-1) and qsort(v, last+1, right).


.. git_changelog::

.. seealso::

   * :c-suggest-improve:`sec_5.6_pointer_arrays.c`
   * :c-better-explain:`sec_5.6_pointer_arrays.rst`

