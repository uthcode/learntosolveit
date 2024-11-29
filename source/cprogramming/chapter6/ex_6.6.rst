===============================
Exercise 6.6 - define processor
===============================

Question
========

Implement a simple version of the #define processor (i.e., no arguments)
suitable for use with C programs, based on the routines of this section. You may
also find getch and ungetch helpful.

.. literalinclude:: cprogs/ex_6.6.c
   :language: c
   :tab-width: 4

Explanation
===========

This implements a simple version of `#define` pre-processor used in C programs.
In the program program it identifies `#define key value` in the given text, and then using the previously taught
concepts of install, lookup and undef to create a hash table, to keep track of the identified key value pairs in
a hash table.

Example output.

::

	#define key value x
	key->value




