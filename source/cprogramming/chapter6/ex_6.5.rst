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

This program demonstrates implementing a hash table for inserting key -> value.
When there is a collision to inserting values against a key, it will create a linked list of values.

So, it implements

* install - installs the word in the hash table. Creates a linked list for the new value.
* lookup - looks up the word in the hash table.
* undef - removes the word in the hash table.

For each of these operations, it takes word, calculates the hash value.
If there is a collision, it will add the word to the linked list in the hashtable key.

Sample run of this program.

::

	key1->value1
	key2->value2
	key3->value3
	key not found
	key1->value1
	key2->value2
	key not found


	

