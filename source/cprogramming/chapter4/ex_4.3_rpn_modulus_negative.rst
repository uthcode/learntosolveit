========================================================
Exercise 4.3 - RPN modulus operator and negative numbers
========================================================

Question
========

Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers.

.. literalinclude:: cprogs/Ex_4.3_rpn_modulus_negative.c
   :language: c
   :tab-width: 4

Explanation
===========

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
stack. When it encounters a `\n` it will pop out the last stored number in the
stack and gives the result.

Thus our operation of the RPN calculator for few inputs look like this.


::

   10 10 + 100 + 2 *
	   240
   500 2 *
	   1000
   100 3 /
	   33.333333
   -10 -10 -
	   0
   20 -10 +
	   10
   -20 10 +
	   -10
   -10 -10 +
	   -20
