=======================================================
Exercise 2.2 - Write getline without && and || operator
=======================================================

Question
========

For example, here is a loop from the input function getline that we
wrote in Chapter 1::

	for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;


Write a loop equivalent to the for loop above without using && or ||.


.. literalinclude:: cprogs/ex_2.2_getline_without_and_or.c
   :language: c


Explanation
===========

We use _getline instead of getline, so that our compiler does not get confused
with the builtin getline function.

The crux of the program is this.

::

	for(i=0; i < lim - 1 ;++i) {
		c = getchar();
		if (c == EOF)
			break;
		if (c == '\n')
			break;
		s[i] = c;
	}


Here we removed `c = getchar()` from the loop condition testing and we **enter**
the loop and then check for conditions like EOF and \n. If we encounter those
undesirable condition, we simply break out of the for loop.

This is equivalent to the for loop above in the question which uses && condition
to check.
