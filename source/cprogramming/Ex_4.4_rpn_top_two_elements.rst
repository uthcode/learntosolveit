===================================================================================
Exercise 4.4 - RPN Calculator - print two top elements of the stack without popping
===================================================================================

Question
========

Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.

.. literalinclude:: ../../languages/cprogs/Ex_4.4_rpn_top_two_elements.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.4_rpn_top_two_elements.c
   :language: c
   :codesite: ideone

Explaination
============

This program has number of helper functions like getop, push and pop, which we
use to the implement the reverse polish notation calculator.


The function getop takes a string and determines if it is number. If it is a
number, both integer or decimal, it will store that number in the array and
return a flag NUMBER which states that number is found. It will push that number
to the stack. If it getop returns an operator like +, -, * or /, it will pop two
numbers out of the stack and operate on it. When it encounters a /, it ensures
that the second operand is not 0 and disallows.


It pushes each number to the stack and when it finds an operand, it will pop out
two numbers in the stack and operate on it and push the result back into the
stack. When it encounters a n it will pop out the last stored number in the
stack and gives the result.
When the hits clearsp it clears the stack.



.. seealso::

   * :c-suggest-improve:`Ex_4.4_rpn_top_two_elements.c`
   * :c-better-explain:`Ex_4.4_rpn_top_two_elements.rst`
