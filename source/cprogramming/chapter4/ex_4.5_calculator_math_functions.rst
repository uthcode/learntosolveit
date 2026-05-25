==============================================
4.5 RPN Calculator with mathematical functions
==============================================

Question
========

Add access to library functions like sin, exp, and pow.

.. coderun:: cprogs/ex_4.5_calculator_math_functions.c
   :language: c


Explanation
===========

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



Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20RPN%20calculator%20with%20math%20function%20dispatch%20%2A%2F%0A%23include%20%3Cmath.h%3E%0A%23include%20%3Cstdio.h%3E%0A%23define%20MAXVAL%2010%0Aint%20sp%20%3D%200%3B%0Adouble%20val%5BMAXVAL%5D%3B%0Avoid%20push%28double%20f%29%20%7B%20if%20%28sp%20%3C%20MAXVAL%29%20val%5Bsp%2B%2B%5D%20%3D%20f%3B%20%7D%0Adouble%20pop%28void%29%20%7B%20return%20sp%20%3E%200%20%3F%20val%5B--sp%5D%20%3A%200.0%3B%20%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20%2F%2A%202%203%20%2B%20%3D%205%2C%20then%20sin%280%29%20%2A%2F%0A%20%20%20%20push%282%29%3B%20push%283%29%3B%0A%20%20%20%20push%28pop%28%29%20%2B%20pop%28%29%29%3B%0A%20%20%20%20printf%28%22%25.8g%5Cn%22%2C%20pop%28%29%29%3B%0A%20%20%20%20printf%28%22sin%280%29%3A%20%25.4f%5Cn%22%2C%20sin%280.0%29%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
