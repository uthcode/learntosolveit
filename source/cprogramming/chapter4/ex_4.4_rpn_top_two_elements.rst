===================================================================================
Exercise 4.4 - RPN Calculator - print two top elements of the stack without popping
===================================================================================

Question
========

Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the
stack.

.. literalinclude:: cprogs/ex_4.4_rpn_top_two_elements.c
   :language: c

Explanation
===========

This program has number of helper functions like getop, push and pop, which we
use to the implement the reverse polish notation calculator. It enhances the RPN
calculator with additional features like `d` to double the entries of the top
two elements, `s` to swap the entries of the top two elements, `?` to display
the top element and finally `c` to clear the stack.

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

On d, It doubles the characters.

On s, It swaps the characters.

On c, It clears the characters in the stack.

On ?, It goes to the top element of the stack.

So here is how the expression is evaluated.

::

   1 d +  3 s ?
        2
        2
   ?
        3
        3
   ?

It takes 1 and `d` doubles it. So our stack will be `1 1`. And then when it sees
`+`, it will add the two values and substitute with the result. So our stack
will now be `2`. We push 3 to the stack and `s` swaps it. Our stack will be `3
2`. So when we input `?` and enter. We get the top element `2` out. And then
pressing `?` again will pop next element `3`.

Visualize It
============

* https://pythontutor.com


Try It
======


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex44rpntoptwoelements?embed=true"></iframe>
