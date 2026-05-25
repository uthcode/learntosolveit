=====================
7.6 Compare Two files
=====================

Question
========

Write a program to compare two files, printing the first line where they differ.

.. coderun:: cprogs/ex_7.6.c
   :language: c
   :tab-width: 4

Explanation
===========


This program reads two files using two file pointers, get one character at a time from each file and compares them,
and if they are not same, prints their differences.

::

        if (f1 != f2) {
            putchar(f1);
            putchar(f2);
            break;
        }



Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20compare%20two%20sequences%20line-by-line%2C%20report%20first%20difference%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20%2Afile1%5B%5D%20%3D%20%7B%22hello%22%2C%20%22world%22%2C%20NULL%7D%3B%0A%20%20%20%20char%20%2Afile2%5B%5D%20%3D%20%7B%22hello%22%2C%20%22there%22%2C%20NULL%7D%3B%0A%20%20%20%20int%20i%20%3D%200%3B%0A%20%20%20%20while%20%28file1%5Bi%5D%20%26%26%20file2%5Bi%5D%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28strcmp%28file1%5Bi%5D%2C%20file2%5Bi%5D%29%20%21%3D%200%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22First%20diff%3A%20%27%25s%27%20vs%20%27%25s%27%5Cn%22%2C%20file1%5Bi%5D%2C%20file2%5Bi%5D%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
