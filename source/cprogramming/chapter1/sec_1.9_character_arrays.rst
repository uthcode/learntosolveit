====================
1.9 Character Arrays
====================


Program
=======

.. coderun:: cprogs/sec_1.9_character_arrays.c
   :language: c

Explanation
===========

In C, strings are nothing but a character arrays which end with a special
character `\0`. In this program, we declare character arrays `char line[]`  in
the geline function and then `char to[]` and `char from[]` in the copy function.
Since arrays are passed by **reference**, so when we send `to` and `from` the
calling program, the function copies the contents to the `to` array and we are
reference the `to` array further from the main program itself. This is
demonstrated by copying line to the longest and then printing the longest in the
main program.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20find%20longest%20of%20two%20strings%20using%20copy%20function%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Avoid%20copy%28char%20to%5B%5D%2C%20char%20from%5B%5D%29%3B%0Aint%20main%28%29%20%7B%0A%20%20%20%20char%20s1%5B%5D%20%3D%20%22hi%22%2C%20s2%5B%5D%20%3D%20%22hello%22%2C%20longest%5B10%5D%3B%0A%20%20%20%20int%20len1%20%3D%202%2C%20len2%20%3D%205%3B%0A%20%20%20%20if%20%28len1%20%3E%20len2%29%20copy%28longest%2C%20s1%29%3B%0A%20%20%20%20else%20copy%28longest%2C%20s2%29%3B%0A%20%20%20%20printf%28%22%25s%5Cn%22%2C%20longest%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0Avoid%20copy%28char%20to%5B%5D%2C%20char%20from%5B%5D%29%20%7B%0A%20%20%20%20int%20i%20%3D%200%3B%0A%20%20%20%20while%20%28%28to%5Bi%5D%20%3D%20from%5Bi%5D%29%20%21%3D%20%27%5C0%27%29%20%2B%2Bi%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
