==============================================================
Exercise 4.14 - swap that interchanges two arguments of type t
==============================================================

Question
========

Define a macro swap(t,x,y) that interchanges two arguments of type t.

.. literalinclude:: cprogs/ex_4.14_swap_t_x_y.c
   :language: c

Explanation
===========

There are two types of macros in C namely object-like and function-like. In
object type, we do substitution and in function macros we can send a variable as
argument. In this program we are going to use function-like macro to swap.

We do this by defining macro::

	#define swap(t,x,y) { t _z; \
                         _z = x;\
                         x = y;\
                         y = _z; }

In the macro, we send type `t` as an argument and two variables `x` and `y` to
swap. We create a temperorary variable called `_z` of type `t` and use it to
swap `x` and `y`.

Visualize It
============

.. raw:: html

   <iframe width="100%" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%0A%23define%20swap%28t,%20x,%20y%29%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5C%0A%20%20%20%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5C%0A%20%20%20%20%20%20%20%20t%20temp%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5C%0A%20%20%20%20%20%20%20%20temp%20%3D%20x%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5C%0A%20%20%20%20%20%20%20%20x%20%3D%20y%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5C%0A%20%20%20%20%20%20%20%20y%20%3D%20temp%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5C%0A%20%20%20%20%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20int%20x%20%3D%201%3B%0A%20%20%20%20int%20y%20%3D%202%3B%0A%20%20%20%20printf%28%22x%20%3D%20%25d,%20y%20%3D%20%25d%5Cn%22,%20x,%20y%29%3B%0A%20%20%20%20swap%28int,%20x,%20y%29%3B%0A%20%20%20%20printf%28%22x%20%3D%20%25d,%20y%20%3D%20%25d%5Cn%22,%20x,%20y%29%3B%0A%20%20%20%20return%200%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=true&curInstr=0&heapPrimitives=false&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=true"> </iframe>


Try It
======


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex414swaptxy?embed=true"></iframe>
