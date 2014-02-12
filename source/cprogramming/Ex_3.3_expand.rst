==============================================================
Exercise 3.3 - expand short hand notation in s1 into string s2
==============================================================

Question
========

Write a function expand(s1,s2) that expands shorthand notations like a-z in the
string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing -is taken literally.

.. literalinclude:: ../../languages/cprogs/Ex_3.3_expand.c
   :language: c
   :tab-width: 4
   

.. runcode:: ../../languages/cprogs/Ex_3.3_expand.c
   :language: c
   :codesite: ideone
   

Explaination
============


.. seealso::

   * :c-suggest-improve:`Ex_3.3_expand.c`
   * :c-better-explain:`Ex_3.3_expand.rst`
