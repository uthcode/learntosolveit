========================================================
Exercise 4.3 - RPN modulus operator and negative numbers
========================================================

Question
========

Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers.

.. literalinclude:: cprogs/ex_4.3_rpn_modulus_negative.c
   :language: c

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

Visualize It
============

.. raw:: html

   <iframe width="100%" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cmath.h%3E%0A%23include%20%3Cstring.h%3E%0A%23define%20MAXOP%20100%0A%23define%20NUMBER%20'0'%0Aint%20getop%28char%20%5B%5D%29%3B%0Avoid%20push%28double%29%3B%0Adouble%20pop%28void%29%3B%0A%0Aint%20main%28int%20argc,%20char%20*argv%5B%5D%29%20%7B%0A%20%20%20%20int%20type%3B%0A%20%20%20%20double%20op2%3B%0A%20%20%20%20char%20s%5BMAXOP%5D%3B%0A%0A%20%20%20%20while%20%28%28type%20%3D%20getop%28s%29%29%20!%3D%20EOF%29%20%7B%0A%20%20%20%20%20%20%20%20switch%28type%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20NUMBER%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20push%28atof%28s%29%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20'%2B'%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20push%28pop%28%29%20%2B%20pop%28%29%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20'*'%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20push%28pop%28%29%20*%20pop%28%29%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20'-'%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20push%28pop%28%29%20-%20pop%28%29%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20'/'%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20op2%20%3D%20pop%28%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20if%20%28op2%20!%3D%200.0%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20push%28pop%28%29%20/%20op2%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22error%3A%5Cn%22%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20'%25'%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22not%20implemented%20in%20visualization%22%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20'%5Cn'%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22%5Ct%25.8g%5Cn%22,%20pop%28%29%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20default%3A%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22error%25s%5Cn%22,%20s%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A%0A%23define%20MAXVAL%20100%0A%0Aint%20sp%20%3D%200%3B%0Adouble%20val%5BMAXVAL%5D%3B%0A%0Avoid%20push%28double%20f%29%0A%7B%0A%20%20%20%20if%20%28sp%20%3C%20MAXVAL%29%0A%20%20%20%20%20%20%20%20val%5Bsp%2B%2B%5D%20%3D%20f%3B%0A%20%20%20%20else%0A%20%20%20%20%20%20%20%20printf%28%22error%20%25g%5Cn%22,%20f%29%3B%0A%7D%0A%0Adouble%20pop%28void%29%0A%7B%0A%20%20%20%20if%20%28sp%20%3E%200%29%0A%20%20%20%20%20%20%20%20return%20val%5B--sp%5D%3B%0A%20%20%20%20else%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22error%3A%20stack%20empty%5Cn%22%29%3B%0A%20%20%20%20%20%20%20%20return%200.0%3B%0A%20%20%20%20%7D%0A%7D%0A%23include%20%3Cctype.h%3E%0Aint%20getch%28void%29%3B%0Avoid%20ungetch%28int%29%3B%0A%0Aint%20getop%28char%20s%5B%5D%29%20%7B%0A%20%20%20%20int%20i,%20c%3B%0A%0A%20%20%20%20while%20%28%28s%5B0%5D%20%3D%20c%20%3D%20getch%28%29%29%20%3D%3D%20'%20'%20%7C%7C%20c%20%3D%3D%20'%5Ct'%29%0A%20%20%20%20%20%20%20%20%3B%0A%0A%20%20%20%20s%5B1%5D%20%3D%20'%5C0'%3B%0A%0A%20%20%20%20if%20%28!isdigit%28c%29%20%26%26%20c%20!%3D%20'.'%20%26%26%20c%20!%3D%20'-'%29%0A%20%20%20%20%20%20%20%20return%20c%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%0A%20%20%20%20if%20%28%20c%20%3D%3D%20'-'%20%7C%7C%20isdigit%28c%29%29%0A%20%20%20%20%20%20%20%20while%20%28isdigit%28s%5B%2B%2Bi%5D%20%3D%20c%20%3D%20getch%28%29%29%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%3B%0A%0A%20%20%20%20if%20%28%20c%20%3D%3D%20'.'%29%0A%20%20%20%20%20%20%20%20while%20%28isdigit%28s%5B%2B%2Bi%5D%20%3D%20c%20%3D%20getch%28%29%29%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%3B%0A%0A%20%20%20%20s%5Bi%5D%20%3D%20'%5C0'%3B%0A%0A%20%20%20%20if%20%28c%20!%3D%20EOF%29%0A%20%20%20%20%20%20%20%20ungetch%28c%29%3B%0A%0A%20%20%20%20if%20%28strcmp%28s,%20%22-%22%29%20%3D%3D%200%29%0A%20%20%20%20%20%20%20%20return%20%22-%22%3B%0A%0A%20%20%20%20return%20NUMBER%3B%0A%7D%0A%0A%23define%20BUFSIZE%20100%0A%0Achar%20buf%5BBUFSIZE%5D%3B%0Aint%20bufp%20%3D%200%3B%0A%0A%0Aint%20getch%28void%29%0A%7B%0A%20%20%20%20return%20%28bufp%20%3E%200%29%20%3F%20buf%5B--bufp%5D%20%3A%20getchar%28%29%3B%0A%7D%0A%0Avoid%20ungetch%28int%20c%29%0A%7B%0A%20%20%20%20if%20%28bufp%20%3E%3D%20BUFSIZE%29%0A%20%20%20%20%20%20%20%20printf%28%22ungetch%3A%20too%20many%20characters%5Cn%22%29%3B%0A%20%20%20%20else%0A%20%20%20%20%20%20%20%20buf%5Bbufp%2B%2B%5D%20%3D%20c%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=true&curInstr=0&heapPrimitives=false&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=true"> </iframe>

Try It
======


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex43rpnmodulusnegative?embed=true"></iframe>
