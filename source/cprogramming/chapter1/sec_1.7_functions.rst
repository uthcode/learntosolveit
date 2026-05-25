=============
1.7 Functions
=============


Program
=======

.. coderun:: cprogs/sec_1.7_functions.c
   :language: c

Explanation
===========

This program is a simple demonstration of functions. A function `power` is
declared to take two integer arguments and return an int value. In the program
we send a number, base and a  number, n to power, and the program returns the
value of base raised to power n.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20defining%20and%20calling%20a%20function%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20power%28int%20base%2C%20int%20n%29%3B%0Aint%20main%28%29%20%7B%0A%20%20%20%20printf%28%22%25d%20%25d%20%25d%5Cn%22%2C%200%2C%20power%282%2C0%29%2C%20power%28-3%2C0%29%29%3B%0A%20%20%20%20printf%28%22%25d%20%25d%20%25d%5Cn%22%2C%201%2C%20power%282%2C1%29%2C%20power%28-3%2C1%29%29%3B%0A%20%20%20%20printf%28%22%25d%20%25d%20%25d%5Cn%22%2C%202%2C%20power%282%2C2%29%2C%20power%28-3%2C2%29%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0Aint%20power%28int%20base%2C%20int%20n%29%20%7B%0A%20%20%20%20int%20i%2C%20p%20%3D%201%3B%0A%20%20%20%20for%20%28i%20%3D%201%3B%20i%20%3C%3D%20n%3B%20%2B%2Bi%29%20p%20%3D%20p%20%2A%20base%3B%0A%20%20%20%20return%20p%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
