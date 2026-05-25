=================================
1.10 External Variables and Scope
=================================

Program
=======

.. coderun:: cprogs/sec_1.10_external_variables.c
   :language: c

Explanation
===========

This program is same as finding the length of the longest line. The special
thing here is we use external variables declared outside of any functions in the
program and reference them within the functions by using the type **extern**.
Here we see the integer max, strings line and longest declared outside of the
main function, and those variables are referenced using **extern** type in main,
getline and in copy function so that all these functions act upon the same
variable. That is the reason, unlike the previous programs, we do not send the
line and the longest as arguments to getline and copy, and neither we have to
return the length from getline, because sharing of those is accomplished by
sharing of the variable themselves.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20external%20%28global%29%20variables%20shared%20between%20functions%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20max%3B%0Achar%20longest%5B10%5D%3B%0Achar%20line%5B10%5D%3B%0Avoid%20copy%28void%29%3B%0Aint%20main%28%29%20%7B%0A%20%20%20%20extern%20int%20max%3B%0A%20%20%20%20extern%20char%20longest%5B%5D%2C%20line%5B%5D%3B%0A%20%20%20%20char%20%2Ainputs%5B2%5D%20%3D%20%7B%22hi%22%2C%20%22hello%22%7D%3B%0A%20%20%20%20int%20i%2C%20len%3B%0A%20%20%20%20max%20%3D%200%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%202%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20%20%20%20%20len%20%3D%200%3B%0A%20%20%20%20%20%20%20%20while%20%28inputs%5Bi%5D%5Blen%5D%29%20%7B%20line%5Blen%5D%20%3D%20inputs%5Bi%5D%5Blen%5D%3B%20len%2B%2B%3B%20%7D%0A%20%20%20%20%20%20%20%20line%5Blen%5D%20%3D%20%27%5C0%27%3B%0A%20%20%20%20%20%20%20%20if%20%28len%20%3E%20max%29%20%7B%20max%20%3D%20len%3B%20copy%28%29%3B%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22%25s%5Cn%22%2C%20longest%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0Avoid%20copy%28void%29%20%7B%0A%20%20%20%20extern%20char%20line%5B%5D%2C%20longest%5B%5D%3B%0A%20%20%20%20int%20i%20%3D%200%3B%0A%20%20%20%20while%20%28%28longest%5Bi%5D%20%3D%20line%5Bi%5D%29%20%21%3D%20%27%5C0%27%29%20%2B%2Bi%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
