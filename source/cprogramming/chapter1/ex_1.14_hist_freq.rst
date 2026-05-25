=========================================
1.14 Histogram of Frequency of Characters
=========================================

Question
--------


Write a program to print a histogram of the frequencies of different characters
in its input.


Solution
--------

.. coderun:: cprogs/ex_1.14_hist_freq.c
   :language: c

Explanation
===========

We define a label TNOCHAR 128 for total number of printable characters in ascii
tabel (0 to 127) and we create an array ` int character[TNOCHAR]` to hold the
number of occurances of those characters. As we get each character from the
input, we increment it's count in the character array.

We print the histogram at the end, by looping through the characters of the
array, printing the character and then printing `*` for number of times that
character had occurred.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20frequency%20histogram%20tracking%20only%20%27a%27%2C%20%27b%27%2C%20%27c%27%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22aab%22%3B%0A%20%20%20%20int%20cnt%5B3%5D%20%3D%20%7B0%7D%3B%0A%20%20%20%20int%20i%2C%20j%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20s%5Bi%5D%3B%20%2B%2Bi%29%0A%20%20%20%20%20%20%20%20if%20%28s%5Bi%5D%20%3E%3D%20%27a%27%20%26%26%20s%5Bi%5D%20%3C%3D%20%27c%27%29%20cnt%5Bs%5Bi%5D-%27a%27%5D%2B%2B%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%203%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20%20%20%20%20putchar%28%27a%27%2Bi%29%3B%0A%20%20%20%20%20%20%20%20for%20%28j%20%3D%200%3B%20j%20%3C%20cnt%5Bi%5D%3B%20%2B%2Bj%29%20putchar%28%27%2A%27%29%3B%0A%20%20%20%20%20%20%20%20putchar%28%27%5Cn%27%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
