==============================================================
Exercise 4.14 - swap that interchanges two arguments of type t
==============================================================

Question
========

Define a macro swap(t,x,y) that interchanges two arguments of type t.

.. literalinclude:: ../../languages/cprogs/Ex_4.14_swap_t_x_y.c
   :language: c
   :tab-width: 4

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

References
==========

* `More on C macros`_

.. _More on C macros: http://en.wikipedia.org/wiki/C_preprocessor#Macro_definition_and_expansion



.. seealso::

   * :c-suggest-improve:`Ex_4.14_swap_t_x_y.c`
   * :c-better-explain:`Ex_4.14_swap_t_x_y.rst`
