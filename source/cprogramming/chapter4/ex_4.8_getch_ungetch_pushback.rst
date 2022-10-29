============================================================
Exercise 4.8 - getch and ungetch handling pushback character
============================================================

Question
========

Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly.


.. literalinclude:: cprogs/ex_4.8_getch_ungetch_pushback.c
   :language: c


Explanation
===========

This program maintains a character buffer `char buf=0` which holds a single
character from the input. The function `ungetch(c)` when called places the
character in the input and `getch()`, if it finds the character in the buf,
returns it or it calls `getchar` to get character from the user.


Visualize It
============

.. raw:: html

   <iframe width="100%" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%0Achar%20buf%20%3D%200%3B%0A%0A/*%20getch%3A%20get%20a%20%28possibly%29%20pushed%20back%20character%20*/%0Aint%20getch%28void%29%0A%7B%0A%20%20%20%20int%20c%3B%0A%0A%20%20%20%20if%28buf%20!%3D%200%29%0A%20%20%20%20%20%20%20%20c%20%3D%20buf%3B%0A%20%20%20%20else%0A%20%20%20%20%20%20%20%20c%20%3D%20getchar%28%29%3B%0A%0A%20%20%20%20buf%20%3D%200%3B%0A%20%20%20%20return%20c%3B%0A%7D%0A%0A/*%20ungetch%3A%20push%20a%20character%20back%20into%20input%20*/%0Avoid%20ungetch%28int%20c%29%0A%7B%0A%20%20%20%20if%28buf%20!%3D%200%29%0A%20%20%20%20%20%20%20%20printf%28%22ungetch%3A%20too%20many%20characters%5Cn%22%29%3B%0A%20%20%20%20else%0A%20%20%20%20%20%20%20%20buf%20%3D%20c%3B%0A%7D%0A%0Aint%20main%28void%29%0A%7B%0A%20%20%20%20int%20c%3B%0A%0A%20%20%20%20c%20%3D%20'*'%3B%0A%0A%20%20%20%20ungetch%28c%29%3B%0A%0A%20%20%20%20while%28%28c%3Dgetch%28%29%29%20!%3D%20EOF%29%0A%20%20%20%20%20%20%20%20putchar%28c%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=true&curInstr=0&heapPrimitives=false&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=true"> </iframe>

Try It
======


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex48getchungetchpushback?embed=true"></iframe>
