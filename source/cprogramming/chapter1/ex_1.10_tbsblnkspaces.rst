============================================
1.10 Explicit Tabs, Backslash and Backspaces
============================================

Question
--------

Write a Program to copy its input to its output, replacing each tab by \t,each
backspace by \b, and each backslash by \\. This makes tabs and backspaces
visible in an unambiguous way.

Solution
--------

.. literalinclude:: cprogs/ex_1.10_tbsblnkspaces.c
   :language: c

Explanation
===========

If the program encounters a special character like ``\t`` (tab) or ``\b`` (blank) or
``\\`` (backslash), we explicitly handle that and print a ``\`` , using
putchar('\\') and then the literal character. For rest of the characters we
simply putchar that.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20replace%20tab%2Fbackspace%2Fbackslash%20with%20visible%20two-char%20sequences%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22a%5Ctb%5Cn%22%3B%0A%20%20%20%20int%20i%20%3D%200%2C%20c%3B%0A%20%20%20%20while%20%28%28c%20%3D%20%28unsigned%20char%29s%5Bi%2B%2B%5D%29%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%20%20%20%20%20%28c%20%3D%3D%20%27%5Ct%27%29%20%7B%20putchar%28%27%5C%5C%27%29%3B%20putchar%28%27t%27%29%3B%20%7D%0A%20%20%20%20%20%20%20%20else%20if%20%28c%20%3D%3D%20%27%5Cb%27%29%20%7B%20putchar%28%27%5C%5C%27%29%3B%20putchar%28%27b%27%29%3B%20%7D%0A%20%20%20%20%20%20%20%20else%20if%20%28c%20%3D%3D%20%27%5C%5C%27%29%20%7B%20putchar%28%27%5C%5C%27%29%3B%20putchar%28%27%5C%5C%27%29%3B%20%7D%0A%20%20%20%20%20%20%20%20else%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20putchar%28c%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
