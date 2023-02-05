====================================================
Exercise 5.10 - expr, evaluate rpn from command line
====================================================

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




