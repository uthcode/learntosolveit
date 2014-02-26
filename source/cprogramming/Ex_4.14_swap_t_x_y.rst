==============================================================
Exercise 4.14 - swap that interchanges two arguments of type t
==============================================================

Question
========

Define a macro swap(t,x,y) that interchanges two arguments of type t

.. literalinclude:: ../../languages/cprogs/Ex_4.14_swap_t_x_y.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.14_swap_t_x_y.c
   :language: c
   :codesite: ideone

Explaination
============

There are two types of macros in C namely object-like and function-like.  In this program we are going to use function-like macro to swap.
We do this by defining macro::

	(t,x,y) { t _z; \
             _z = x;\
              x = y;\
              y = _z; }

The Swapping is done in the following manner
Suppose we take 20 and 30 to be swapped

References
==========

* `More on U macros `_

.. _More on U macros: http://en.wikipedia.org/wiki/C_preprocessor#Macro_definition_and_expansion

.. seealso::

   * :c-suggest-improve:`Ex_4.14_swap_t_x_y.c`
   * :c-better-explain:`Ex_4.14_swap_t_x_y.rst`