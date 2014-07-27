=====================================================
Exercise 5.14 - sorting in reverse (decreasing) order
=====================================================

Question
========

Modify the sort program to handle a -r flag, which indicates sorting in reverse
(decreasing) order. Be sure that -r works with -n.

.. literalinclude:: ../../languages/cprogs/Ex_5.14_sortrevnum.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_5.14_sortrevnum.c
   :language: c
   :codesite: ideone

Explanation
===========

This program when executed with flags `-nr` and when given an input in any order
will sort the arguments and print the numbers in reverse order.

For .e.g, when given an input

::

	$ ./mysort -nr
	10
	40
	242
	42
	52

The output was::

	242
	52
	42
	40
	10


The program works by implementing a version of quicksort. In quicksort, we give
two indices, left value (starting 0) and right value (nlines, the number of
lines), we send the array of strings (`char *lineptr[]`) to be sorted and then
we send a comparator function as a pointer too.

The declartion of myqsort looks like this. 

::

	void myqsort(void *v[],int left,int right,int (*comp)(void *,void *));

The comparator function, `numcmp` will return -1, if the first argument is less
than second, it will return 1, if the first argument is greater, otherwise it
will 0. This is a standard way in which many comparator functions are defined.

In the execution of quicksort, it partitions the array into 2, and recursively,
sorts the left half and then the right half. 

Since we have to sort it "in-place", the details of the implementation needs
careful analysis. 

We choose the middle element and move it to extreme left (position 0), the
compare the values, starting with next element (at position 1) upto our right
pointer, the middle of the array.

If we find any values which are less than our element (position 0), we swap it
to left, next to our left element and keep that counter as the last value.

Thus for all the values less then our first element, we might have moved them to
left.

For e.g.

If our first iteration starts like this.

::

	40   45 55 30 10 60   
	^
	left

Our first few iterations will be::

	40  30 45 55 10 60
	^    ^ 
	left  last

	40 30 10 45 55 60
	^     ^
	left  last

And then finally we swap the left and last::

	10 30 40 45 55 60
	^      ^
	last   left

Thus we have a partially sorted left side. Thus by carefully moving the pointers
we sorted the left side comparing each element with the middle element.
Similarly, we do the same for the right half of the array, and then recursively
divide each half to sort it.

The curx of the program is in `myqsort`` function and once that is sorted, the
program displays the  output as we desire.


.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_5.14_sortrevnum.c`
   * :c-better-explain:`Ex_5.14_sortrevnum.rst`
