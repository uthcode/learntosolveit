=======================
6.2 Identical Variables
=======================


Question
========

Write a program that reads a C program and prints in alphabetical order each
group of variable names that are identical in the first 6 characters, but
different somewhere thereafter. Don't count words within strings and comments.
Make 6 a parameter that can be set from the command line.

.. coderun:: cprogs/ex_6.2_identical_variables.c
   :language: c
   :tab-width: 4

Explanation
===========

This program reads a C program and groups similar list of variable names as similar words list.
It parses the C program and stores the variables names in a binary tree, then constructs a similar word list which have
a common prefix length.



Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20binary%20tree%20that%20counts%20word%20occurrences%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstring.h%3E%0Astruct%20tnode%20%7B%20char%20%2Aword%3B%20int%20count%3B%20struct%20tnode%20%2Aleft%2C%20%2Aright%3B%20%7D%3B%0Astruct%20tnode%20%2Aaddtree%28struct%20tnode%20%2Ap%2C%20char%20%2Aw%29%20%7B%0A%20%20%20%20int%20cond%3B%0A%20%20%20%20if%20%28%21p%29%20%7B%0A%20%20%20%20%20%20%20%20p%20%3D%20malloc%28sizeof%28struct%20tnode%29%29%3B%0A%20%20%20%20%20%20%20%20p-%3Eword%20%3D%20strdup%28w%29%3B%20p-%3Ecount%20%3D%201%3B%20p-%3Eleft%20%3D%20p-%3Eright%20%3D%20NULL%3B%0A%20%20%20%20%7D%20else%20if%20%28%28cond%20%3D%20strcmp%28w%2C%20p-%3Eword%29%29%20%3C%200%29%20p-%3Eleft%20%20%3D%20addtree%28p-%3Eleft%2C%20%20w%29%3B%0A%20%20%20%20else%20if%20%28cond%20%3E%200%29%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20p-%3Eright%20%3D%20addtree%28p-%3Eright%2C%20w%29%3B%0A%20%20%20%20else%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20p-%3Ecount%2B%2B%3B%0A%20%20%20%20return%20p%3B%0A%7D%0Avoid%20treeprint%28struct%20tnode%20%2Ap%29%20%7B%0A%20%20%20%20if%20%28p%29%20%7B%20treeprint%28p-%3Eleft%29%3B%20printf%28%22%254d%20%25s%5Cn%22%2C%20p-%3Ecount%2C%20p-%3Eword%29%3B%20treeprint%28p-%3Eright%29%3B%20%7D%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20struct%20tnode%20%2Aroot%20%3D%20NULL%3B%0A%20%20%20%20char%20%2Awords%5B%5D%20%3D%20%7B%22int%22%2C%20%22char%22%2C%20%22int%22%7D%3B%0A%20%20%20%20int%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%203%3B%20i%2B%2B%29%20root%20%3D%20addtree%28root%2C%20words%5Bi%5D%29%3B%0A%20%20%20%20treeprint%28root%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
