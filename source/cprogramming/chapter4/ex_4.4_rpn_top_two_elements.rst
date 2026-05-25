========================================================================
4.4 RPN Calculator - print two top elements of the stack without popping
========================================================================

Question
========

Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the
stack.

.. coderun:: cprogs/ex_4.4_rpn_top_two_elements.c
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

Visualize the Full Solution
---------------------------

* https://pythontutor.com


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20RPN%20calculator%20%E2%80%94%20push%2C%20add%2C%20pop%20result%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23define%20MAXVAL%2010%0Aint%20sp%20%3D%200%3B%0Adouble%20val%5BMAXVAL%5D%3B%0Avoid%20push%28double%20f%29%20%7B%20if%20%28sp%20%3C%20MAXVAL%29%20val%5Bsp%2B%2B%5D%20%3D%20f%3B%20%7D%0Adouble%20pop%28void%29%20%7B%20return%20sp%20%3E%200%20%3F%20val%5B--sp%5D%20%3A%200.0%3B%20%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20%2F%2A%203%204%20%2B%20%3D%207%20%2A%2F%0A%20%20%20%20push%283%29%3B%20push%284%29%3B%0A%20%20%20%20push%28pop%28%29%20%2B%20pop%28%29%29%3B%0A%20%20%20%20printf%28%22%25.8g%5Cn%22%2C%20pop%28%29%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
