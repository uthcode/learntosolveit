=============================================
3.2 escape sequences into the real characters
=============================================

Question
========

Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s. Use a
switch. Write a function for the other direction as well, converting escape
sequences into the real characters.

.. coderun:: cprogs/ex_3.2_escape.c
   :language: c
   :tab-width: 4

Explanation
===========

C Program interpreters ``\n`` and ``\t`` as space characters and outputs them.
Our intention is to capture the ``\n`` and ``\t`` characters and display them
visibly as **\n** or **\t**. In order to do that we need to *escape* them, the
escaping is done by adding ``\`` character.

So in the program as soon as we see a ``\n`` character, in the array where we
are copying to, we copy ``\\`` character and add a ``n`` character and
similarly, when we see a ``\t`` character, in the array where we are copying
to, we copy ``\\`` character and add a ``t`` character.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20convert%20escape%20chars%20%5Ct%20and%20%5Cn%20to%20visible%20two-char%20sequences%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Avoid%20escape%28char%20s%5B%5D%2C%20char%20t%5B%5D%29%20%7B%0A%20%20%20%20int%20i%20%3D%200%2C%20j%20%3D%200%3B%0A%20%20%20%20while%20%28t%5Bi%5D%29%20%7B%0A%20%20%20%20%20%20%20%20switch%20%28t%5Bi%5D%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20%27%5Ct%27%3A%20s%5Bj%2B%2B%5D%20%3D%20%27%5C%5C%27%3B%20s%5Bj%5D%20%3D%20%27t%27%3B%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20case%20%27%5Cn%27%3A%20s%5Bj%2B%2B%5D%20%3D%20%27%5C%5C%27%3B%20s%5Bj%5D%20%3D%20%27n%27%3B%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20default%3A%20%20%20s%5Bj%5D%20%3D%20t%5Bi%5D%3B%20break%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%20j%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20s%5Bj%5D%20%3D%20%27%5C0%27%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20t%5B%5D%20%3D%20%22a%5Ctb%5Cn%22%3B%0A%20%20%20%20char%20s%5B20%5D%3B%0A%20%20%20%20escape%28s%2C%20t%29%3B%0A%20%20%20%20printf%28%22%25s%5Cn%22%2C%20s%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
