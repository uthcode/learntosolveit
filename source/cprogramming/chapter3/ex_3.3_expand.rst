===================================================
3.3 expand short hand notation in s1 into string s2
===================================================

Question
========

Write a function expand(s1,s2) that expands shorthand notations like a-z in the
string s1 into the equivalent complete list abc...xyz in s2. Allow for letters
of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9
and -a-z. Arrange that a leading or trailing -is taken literally.

.. coderun:: cprogs/ex_3.3_expand.c
   :language: c
   :tab-width: 4


Explanation
===========

Here we expand the strings like a-z from s1 into an expanded form in s2. We
utilize the ascii table property that the second character is higher than the
first character and it is incremental.

In the outer while loop, we get the character in c, and then check if the next
character is ``-`` and character beyond that (i+1) is greater than c. With this
check, we ascertain that we are in a range like ``a-z``.

To expand the range, we keep incrementing the character in **c**, till it hits
the end character, storing all the characters in s2.

s2 will now have the expanded string.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20expand%20shorthand%20range%20a-d%20into%20abcd%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Avoid%20expand%28char%20s1%5B%5D%2C%20char%20s2%5B%5D%29%20%7B%0A%20%20%20%20int%20i%20%3D%200%2C%20j%20%3D%200%2C%20c%3B%0A%20%20%20%20while%20%28%28c%20%3D%20s1%5Bi%2B%2B%5D%29%29%0A%20%20%20%20%20%20%20%20if%20%28s1%5Bi%5D%20%3D%3D%20%27-%27%20%26%26%20s1%5Bi%2B1%5D%20%3E%3D%20c%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20while%20%28c%20%3C%20s1%5Bi%5D%29%20s2%5Bj%2B%2B%5D%20%3D%20c%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20s2%5Bj%2B%2B%5D%20%3D%20c%3B%0A%20%20%20%20s2%5Bj%5D%20%3D%20%27%5C0%27%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s2%5B20%5D%3B%0A%20%20%20%20expand%28%22a-d%22%2C%20s2%29%3B%0A%20%20%20%20printf%28%22%25s%5Cn%22%2C%20s2%29%3B%20%20%2F%2A%20abc%20%2A%2F%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
