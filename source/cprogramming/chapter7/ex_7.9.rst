=================================================
Exercise 7.9 - Analyze implementations of isupper
=================================================

Question
========

Functions like isupper can be implemented to save space or to save time. Explore
both possibilities.

.. literalinclude:: cprogs/ex_7.9.c
   :language: c
   :tab-width: 4


Explanation
===========


Visualize
=========

.. raw:: html

   <iframe width="100%" height="800" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=/*%0A%20*%20Functions%20like%20isupper%20can%20be%20implemented%20to%20save%20space%20or%20to%20save%20time.%0A%20*%20Explore%20both%20possibilities.%0A%20*/%0A%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0Aint%20myisupper%28int%29%3B%0A%0Aconst%20char%20*input%20%3D%20%22AbCdEfx%22%3B%0Aint%20input_index%20%3D%200%3B%0A%0Aint%20_getchar%28void%29%20%7B%0A%20%20%20%20if%20%28input%5Binput_index%5D%20%3D%3D%20'%5C0'%29%20%7B%0A%20%20%20%20%20%20%20%20return%20EOF%3B%0A%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20return%20input%5Binput_index%2B%2B%5D%3B%0A%20%20%20%20%7D%0A%7D%0A%0A%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20c%3B%0A%0A%20%20%20%20while%20%28%28c%20%3D%20_getchar%28%29%29%20!%3D%20'x'%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20'%5Cn'%29%0A%20%20%20%20%20%20%20%20%20%20%20%20continue%3B%0A%0A%20%20%20%20%20%20%20%20if%20%28myisupper%28c%29%20%3D%3D%201%29%0A%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22true%5Cn%22%29%3B%0A%20%20%20%20%20%20%20%20else%0A%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22false%5Cn%22%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20EXIT_SUCCESS%3B%0A%7D%0A%0Aint%20myisupper%28int%20c%29%20%7B%0A%20%20%20%20if%20%28c%20%3E%3D%20'A'%20%26%26%20c%20%3C%3D%20'Z'%29%0A%20%20%20%20%20%20%20%20return%201%3B%0A%20%20%20%20else%0A%20%20%20%20%20%20%20%20return%200%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>


