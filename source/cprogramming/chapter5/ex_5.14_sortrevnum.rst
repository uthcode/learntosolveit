==========================================
5.14 sorting in reverse (decreasing) order
==========================================

Question
========

Modify the sort program to handle a -r flag, which indicates sorting in reverse
(decreasing) order. Be sure that -r works with -n.

.. coderun:: cprogs/ex_5.14_sortrevnum.c
   :language: c
   :tab-width: 4

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






Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20sort%20strings%20in%20reverse%20numeric%20order%20using%20function%20pointer%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20numcmp%28char%20%2As1%2C%20char%20%2As2%29%20%7B%0A%20%20%20%20int%20n1%20%3D%200%2C%20n2%20%3D%200%3B%0A%20%20%20%20while%20%28%2As1%20%3E%3D%20%270%27%20%26%26%20%2As1%20%3C%3D%20%279%27%29%20n1%20%3D%20n1%2A10%20%2B%20%2As1%2B%2B%20-%20%270%27%3B%0A%20%20%20%20while%20%28%2As2%20%3E%3D%20%270%27%20%26%26%20%2As2%20%3C%3D%20%279%27%29%20n2%20%3D%20n2%2A10%20%2B%20%2As2%2B%2B%20-%20%270%27%3B%0A%20%20%20%20return%20n2%20-%20n1%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20%2Alines%5B3%5D%20%3D%20%7B%223%22%2C%20%221%22%2C%20%222%22%7D%3B%0A%20%20%20%20int%20i%2C%20j%3B%0A%20%20%20%20char%20%2Atmp%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%202%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20for%20%28j%20%3D%20i%2B1%3B%20j%20%3C%203%3B%20j%2B%2B%29%0A%20%20%20%20%20%20%20%20%20%20%20%20if%20%28numcmp%28lines%5Bi%5D%2C%20lines%5Bj%5D%29%20%3E%200%29%20%7B%20tmp%20%3D%20lines%5Bi%5D%3B%20lines%5Bi%5D%20%3D%20lines%5Bj%5D%3B%20lines%5Bj%5D%20%3D%20tmp%3B%20%7D%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%203%3B%20i%2B%2B%29%20printf%28%22%25s%5Cn%22%2C%20lines%5Bi%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
