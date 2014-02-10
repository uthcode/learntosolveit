======================================================================
Exercise 2.5 - return the first location in the string s1 comparing s2
======================================================================

Question
========

Write the function any(s1,s2), which returns the first location in a string s1 where any
character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library
function strpbrk does the same job but returns a pointer to the location.)

.. literalinclude:: ../../languages/cprogs/Ex_2.5_any.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_2.5_any.c
   :language: c
   :codesite: ideone

Explaination
============



.. seealso::

   * :c-suggest-improve:`Ex_2.5_any.c`
   * :c-better-explain:`Ex_2.5_any.rst`