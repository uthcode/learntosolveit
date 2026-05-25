=======================================
5.15 fold upper and lower case together
=======================================

Question
========

Add the option -f to fold upper and lower case together, so that case
distinctions are not made during sorting; for example, a and A compare equal.

.. coderun:: cprogs/ex_5.15_sortfnr.c
   :language: c
   :tab-width: 4


Explanation
===========


This is a sort function, which sorts the given input lines. But this function adds a flag `-f` which introduces case insensitive folding.

::

    ./ex_5.15_sortfnr -f
    hello
    Hello
    Apple
    Apple
    Hello
    hello







Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20sort%20using%20a%20function%20pointer%20for%20comparison%20strategy%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0Aint%20cmpforward%28char%20%2A%2Aa%2C%20char%20%2A%2Ab%29%20%7B%20return%20strcmp%28%2Aa%2C%20%2Ab%29%3B%20%7D%0Aint%20cmpbackward%28char%20%2A%2Aa%2C%20char%20%2A%2Ab%29%20%7B%20return%20strcmp%28%2Ab%2C%20%2Aa%29%3B%20%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20%2Alines%5B3%5D%20%3D%20%7B%22banana%22%2C%20%22apple%22%2C%20%22cherry%22%7D%3B%0A%20%20%20%20int%20%28%2Acmp%29%28char%20%2A%2A%2C%20char%20%2A%2A%29%20%3D%20cmpforward%3B%0A%20%20%20%20int%20i%2C%20j%3B%0A%20%20%20%20char%20%2Atmp%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%202%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20for%20%28j%20%3D%20i%2B1%3B%20j%20%3C%203%3B%20j%2B%2B%29%0A%20%20%20%20%20%20%20%20%20%20%20%20if%20%28cmp%28%26lines%5Bi%5D%2C%20%26lines%5Bj%5D%29%20%3E%200%29%20%7B%20tmp%20%3D%20lines%5Bi%5D%3B%20lines%5Bi%5D%20%3D%20lines%5Bj%5D%3B%20lines%5Bj%5D%20%3D%20tmp%3B%20%7D%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%203%3B%20i%2B%2B%29%20printf%28%22%25s%5Cn%22%2C%20lines%5Bi%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
