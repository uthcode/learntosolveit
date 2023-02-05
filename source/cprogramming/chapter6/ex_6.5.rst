===========================================================
Exercise 6.5 - undef: remove name and definition from table
===========================================================

Question
========

Write a function undef that will remove a name and definition from the table
maintained by lookup and install.

.. literalinclude:: cprogs/ex_6.5.c
   :language: c
   :tab-width: 4

Explanation
===========

Sample run of this program.

::

	key1->value1
	key2->value2
	key3->value3
	key not found
	key1->value1
	key2->value2
	key not found


	
.. seealso::

   * :c-suggest-improve:`Ex_6.5.c`
   * :c-better-explain:`Ex_6.5.rst`
