================================================
Section 4.3 - Reverse Polish Notation Calculator
================================================

Program
=======

.. literalinclude:: ../../languages/cprogs/sec_4.3.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/sec_4.3.c
   :language: c
   :codesite: ideone


Explaination
============

This program has number of helper functions like `getop`, `push` and `pop`,
which we use to the implement the reverse polish notation calculator.

The function `getop` takes a string and determines if it is number. If it is a
number, both integer or decimal, it will store that number in the array and
return a flag `NUMBER` which states that number is found. It will push that
number to the stack. If it getop returns an operator like `+`, `-`, `*` or `/`,
it will `pop` two numbers out of the stack and operate on it. When it encounters
a `/`, it ensures that the second operand is not 0 and disallows.


.. git_changelog::

.. seealso::

   * :c-suggest-improve:`sec_4.3.c`
   * :c-better-explain:`sec_4.3.rst`
