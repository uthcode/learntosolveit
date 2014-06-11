=========================================================
Exercise 4.5 - RPN Calculator with mathematical functions
=========================================================

Question
========

Add access to library functions like sin, exp, and pow.

.. literalinclude:: ../../languages/cprogs/Ex_4.5_calculator_math_functions.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.5_calculator_math_functions.c
   :language: c
   :codesite: ideone

Explaination
============

The RPN calculator has addition features like doing mathematical functions. In the input, if a string is given then the
calculator identifies it as a NAME and goes to the mathfun.

In the mathfun, the string input is compared with "sin" and if it is a sin, the mathematical function `sin` is called on
the popped value. If the intput is `cos`, the cosine function is called and if the input is "pow", then first value is
popped and stored in `op2` and second value is raised to the power of op2.


The curx of program is in this function.

::

   void mathfnc(char s[])
   {
       double op2;
       
       if(strcmp(s,"sin")==0)
           push(sin(pop()));
       else if(strcmp(s,"cos")==0)
           push(cos(pop()));
       else if(strcmp(s,"exp")==0)
           push(exp(pop()));
       else if(strcmp(s,"pow")==0)
       {
           op2 = pop();
           push(pow(pop(),op2));
       }
       else
           printf("error: %s is not supported\n",s);
   }


.. git-changelog::


.. seealso::

   * :c-suggest-improve:`Ex_4.5_calculator_math_functions.c`
   * :c-better-explain:`Ex_4.5_calculator_math_functions.rst`
