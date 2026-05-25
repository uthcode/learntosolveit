=======================================
7.7 Pattern matching program with files
=======================================

Question
========

Modify the pattern finding program of Chapter 5 to take its input from a set of
named files or, if no files are named as arguments, from the standard input.
Should the file name be printed when a matching line is found?

.. coderun:: cprogs/ex_7.7.c
   :language: c
   :tab-width: 4

Explanation
===========

This program searches for a pattern `char pattern[] = "ould";`` in the given input line.
The idea of this program is to take the input from a file.





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20pattern%20search%20%E2%80%94%20print%20lines%20containing%20the%20pattern%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0Aint%20strindex%28char%20%2As%2C%20char%20%2At%29%20%7B%0A%20%20%20%20char%20%2Ab%20%3D%20s%2C%20%2Ap%2C%20%2Ar%3B%0A%20%20%20%20for%20%28%3B%20%2As%3B%20s%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20for%20%28p%20%3D%20s%2C%20r%20%3D%20t%3B%20%2Ar%20%26%26%20%2Ap%20%3D%3D%20%2Ar%3B%20p%2B%2B%2C%20r%2B%2B%29%3B%0A%20%20%20%20%20%20%20%20if%20%28r%20%3E%20t%20%26%26%20%21%2Ar%29%20return%20s%20-%20b%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20-1%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20%2Alines%5B%5D%20%3D%20%7B%22would%20you%20like%20it%22%2C%20%22solve%20it%20now%22%2C%20NULL%7D%3B%0A%20%20%20%20char%20%2Apattern%20%3D%20%22ould%22%3B%0A%20%20%20%20int%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20lines%5Bi%5D%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20if%20%28strindex%28lines%5Bi%5D%2C%20pattern%29%20%3E%3D%200%29%20printf%28%22%25s%5Cn%22%2C%20lines%5Bi%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
