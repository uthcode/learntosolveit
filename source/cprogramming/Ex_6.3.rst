===============================
Exercise 6.3 - Cross Referencer
===============================

Question
========

Write a cross-referencer that prints a list of all words in a document, and for
each word, a list of the line numbers on which it occurs. Remove noise words
like ``the,'' ``and,'' and so on.

.. literalinclude:: ../../languages/cprogs/Ex_6.3.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_Ex_6.3.c
   :language: c
   :codesite: ideone

Explaination
============

Here is an example execution of this program.

This is a
cross reference
word
document
creator
lists words and their line numbers.
Gets the word and puts their line numbers.
x

Words with line numbers

Gets :6,
This :0,
a :0,
and :5,6,
creator :4,
cross :1,
document :3,
is :0,
line :5,6,
lists :5,
numbers :5,6,
puts :6,
reference :1,
the :6,
their :5,6,
word :2,6,
words :5,


.. seealso::

   * :c-suggest-improve:`Ex_6.3.c`
   * :c-better-explain:`Ex_6.3.rst`
