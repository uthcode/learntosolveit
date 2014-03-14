========================================================================
Exercise 4.12 - convert integer into string by calling recursive routine
========================================================================

Question
========

Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.

.. literalinclude:: ../../languages/cprogs/Ex_4.12_recursive_itoa.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.12_recursive_itoa.c
   :language: c
   :codesite: ideone

Explaination
============

TODO (Avinash):  Start the explaination.

For e.g. when when we send the input 20 to the program.

1. itoa is called for 20,s
2. itoa is called for 2,s
3. Call 2. returns and itoa creates a string '2'
4. Call 1. continues and itoa creates a string '20'

.. seealso::

   * :c-suggest-improve:`Ex_4.12_recursive_itoa.c`
   * :c-better-explain:`Ex_4.12_recursive_itoa.rst`
