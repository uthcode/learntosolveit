=========================================
5.10 expr, evaluate rpn from command line
=========================================

Question
========

Write the program expr, which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument.

.. literalinclude:: cprogs/ex_5.10_exprcmd.c
   :language: c
   :tab-width: 4

Explanation
===========

This program reads the input to our rpn calculator from the command line itself.
`2 3 4 + *` and then goes about doing the RPN caculator work on it.

The main function has a signature now, that is `int main(int argc, char
*argv[])`, that is it takes the command line args, **argc** for count of the
args and **argv** is the array which stores the arguments.

So, 2, 3, 4, +, * will be stored in the array **agrv** as strings. In this
program, we go about by getting each argument from argv and then giving that as
the input to our RPN calculator, like the program in sec_4.3. If we find an
operand, using the push function, we push it to the stack and  when we find a
operator in the input, we pop() the two operands out of the stack and do the
operation.





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20RPN%20eval%20%E2%80%94%20push%20operands%2C%20pop%20and%20operate%2C%20print%20result%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20sp%20%3D%200%3B%0Adouble%20val%5B4%5D%3B%0Avoid%20push%28double%20v%29%20%7B%20if%20%28sp%20%3C%204%29%20val%5Bsp%2B%2B%5D%20%3D%20v%3B%20%7D%0Adouble%20pop%28void%29%20%20%20%20%7B%20return%20sp%20%3E%200%20%3F%20val%5B--sp%5D%20%3A%200.0%3B%20%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20push%283.0%29%3B%20push%284.0%29%3B%0A%20%20%20%20double%20op2%20%3D%20pop%28%29%3B%0A%20%20%20%20push%28pop%28%29%20%2B%20op2%29%3B%0A%20%20%20%20printf%28%223%204%20%2B%20%3D%20%25.0f%5Cn%22%2C%20pop%28%29%29%3B%0A%20%20%20%20push%286.0%29%3B%20push%282.0%29%3B%0A%20%20%20%20op2%20%3D%20pop%28%29%3B%0A%20%20%20%20push%28pop%28%29%20%2F%20op2%29%3B%0A%20%20%20%20printf%28%226%202%20%2F%20%3D%20%25.0f%5Cn%22%2C%20pop%28%29%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
