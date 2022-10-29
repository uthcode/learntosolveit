========================================================
Exercise 4.2 - Extend atof to handle scientific notation
========================================================

Question
========

Exercise 4 - 2. Extend atof to handle scientific notation of the form 123.45e-6
where a floating-point number may be followed by e or E and an optionally
signed exponent.


.. literalinclude:: cprogs/ex_4.2_atof_scientific.c
   :language: c

Explanation
===========

For the input::

   1.0e10

We might get the output::

   1410065408.000000

Visualize It
============

.. raw:: html

   <iframe width="100%" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cctype.h%3E%0A%0A%23define%20MAXLINE%20100%0A%0Adouble%20atof%28char%20s%5B%5D%29%3B%0Aint%20mgetline%28char%20s%5B%5D,%20int%20lim%29%3B%0A%0Aint%20main%28int%20argc,%20char%20*argv%5B%5D%29%0A%7B%0A%20%20%20%20char%20str%5BMAXLINE%5D%3B%0A%20%20%20%20double%20val%3B%0A%0A%20%20%20%20mgetline%28str,%20MAXLINE%29%3B%0A%0A%20%20%20%20val%20%3D%20atof%28str%29%3B%0A%0A%20%20%20%20printf%28%22%25f%22,%20val%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D%0A%0Adouble%20atof%28char%20s%5B%5D%29%0A%7B%0A%20%20%20%20double%20val,%20pow%3B%0A%20%20%20%20int%20sign,%20i,%20esign,%20exp%3B%0A%0A%20%20%20%20int%20power%28int%20base,%20int%20exp%29%3B%0A%0A%20%20%20%20for%20%28i%20%3D%200%3B%20isspace%28s%5Bi%5D%29%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20%3B%0A%0A%20%20%20%20sign%20%3D%20%28s%5Bi%5D%20%3D%3D%20'-'%29%20%3F%20-1%20%3A%201%3B%0A%0A%20%20%20%20if%20%28s%5Bi%5D%20%3D%3D%20'%2B'%20%7C%7C%20s%5Bi%5D%20%3D%3D%20'-'%29%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%0A%20%20%20%20for%20%28val%20%3D%200.0%3B%20isdigit%28s%5Bi%5D%29%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20val%20%3D%2010.0%20*%20val%20%2B%20%28s%5Bi%5D%20-%20'0'%29%3B%0A%0A%20%20%20%20if%20%28s%5Bi%5D%20%3D%3D%20'.'%29%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%0A%20%20%20%20for%20%28pow%20%3D%201.0%3B%20isdigit%28s%5Bi%5D%29%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20val%20%3D%2010.0%20*%20val%20%2B%20%28s%5Bi%5D%20-%20'0'%29%3B%0A%20%20%20%20%20%20%20%20pow%20*%3D%2010.0%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20if%20%28s%5Bi%5D%20%3D%3D%20'e'%20%7C%7C%20s%5Bi%5D%20%3D%3D%20'E'%29%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%0A%20%20%20%20if%20%28s%5Bi%5D%20%3D%3D%20'%2B'%29%0A%20%20%20%20%20%20%20%20esign%20%3D%201%3B%0A%20%20%20%20else%20if%20%28s%5Bi%5D%20%3D%3D%20'-'%29%0A%20%20%20%20%20%20%20%20esign%20%3D%20-1%3B%0A%20%20%20%20else%0A%20%20%20%20%20%20%20%20esign%20%3D%201%3B%0A%0A%20%20%20%20for%20%28exp%20%3D%200%3B%20isdigit%28s%5Bi%5D%29%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20exp%20%3D%2010%20*%20exp%20%2B%20%28s%5Bi%5D%20-%20'0'%29%3B%0A%0A%20%20%20%20if%20%28esign%20%3D%3D%201%29%0A%20%20%20%20%20%20%20%20val%20%3D%20%28val%20/%20pow%29%20*%20power%28exp,%2010%29%3B%0A%20%20%20%20else%0A%20%20%20%20%20%20%20%20val%20%3D%20%28val%20/%20pow%29%20/%20power%28exp,%2010%29%3B%0A%0A%20%20%20%20return%20sign%20*%20val%3B%0A%7D%0A%0Aint%20mgetline%28char%20s%5B%5D,%20int%20lim%29%0A%7B%0A%20%20%20%20int%20c,%20i%3B%0A%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20lim%20-%201%20%26%26%20%28c%20%3D%20getchar%28%29%29%20!%3D%20EOF%20%26%26%20c%20!%3D%20'%5Cn'%3B%20%2B%2Bi%29%0A%20%20%20%20%20%20%20%20s%5Bi%5D%20%3D%20c%3B%0A%0A%20%20%20%20if%20%28c%20%3D%3D%20'%5Cn'%29%20%7B%0A%20%20%20%20%20%20%20%20s%5Bi%5D%20%3D%20c%3B%0A%20%20%20%20%20%20%20%20%2B%2Bi%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20s%5Bi%5D%20%3D%20'%5C0'%3B%0A%0A%20%20%20%20return%20i%3B%0A%7D%0A%0Aint%20power%28int%20base,%20int%20exp%29%0A%7B%0A%20%20%20%20int%20i,%20p%3B%0A%0A%20%20%20%20p%20%3D%201%3B%0A%0A%20%20%20%20for%20%28i%20%3D%201%3B%20i%20%3C%3D%20exp%3B%20%2B%2Bi%29%0A%20%20%20%20%20%20%20%20p%20%3D%20p%20*%20base%3B%0A%0A%20%20%20%20return%20p%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=true&curInstr=0&heapPrimitives=false&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=true"> </iframe>


Try It
======


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex42atofscientific?embed=true"></iframe>
