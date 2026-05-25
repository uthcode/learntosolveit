============================================
2.2 Write getline without && and || operator
============================================

Question
========

For example, here is a loop from the input function getline that we
wrote in Chapter 1::

	for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;


Write a loop equivalent to the for loop above without using && or ||.


.. coderun:: cprogs/ex_2.2_getline_without_and_or.c
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

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20getline%20loop%20written%20without%20%26%26%20or%20%7C%7C%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Avoid%20copy%28char%20to%5B%5D%2C%20const%20char%20from%5B%5D%29%20%7B%0A%20%20%20%20int%20i%20%3D%200%3B%0A%20%20%20%20while%20%28%28to%5Bi%5D%20%3D%20from%5Bi%5D%29%20%21%3D%20%27%5C0%27%29%20%2B%2Bi%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20%2Adata%5B2%5D%20%3D%20%7B%22hi%22%2C%20%22hello%22%7D%3B%0A%20%20%20%20char%20line%5B10%5D%2C%20maxline%5B10%5D%3B%0A%20%20%20%20int%20len%2C%20max%20%3D%200%2C%20i%2C%20j%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%202%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20%20%20%20%20for%20%28j%20%3D%200%3B%20data%5Bi%5D%5Bj%5D%20%26%26%20j%20%3C%209%3B%20j%2B%2B%29%20line%5Bj%5D%20%3D%20data%5Bi%5D%5Bj%5D%3B%0A%20%20%20%20%20%20%20%20line%5Bj%5D%20%3D%20%27%5C0%27%3B%20len%20%3D%20j%3B%0A%20%20%20%20%20%20%20%20if%20%28len%20%3E%20max%29%20%7B%20max%20%3D%20len%3B%20copy%28maxline%2C%20line%29%3B%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20if%20%28max%20%3E%200%29%20printf%28%22%25s%5Cn%22%2C%20maxline%29%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
