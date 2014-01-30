=============
Exercise 1.14
=============

Question
--------


Write a program to print a histogram of the frequencies of different characters
in its input.


Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.14_Hist_Freq.c
   :language: c
   :tab-width: 4

Explaination
------------

We define a label TNOCHAR 128 for total number of printable characters in ascii
tabel (0 to 127) and we create an array ` int character[TNOCHAR]` to hold the
number of occurances of those characters. As we get each character from the
input, we increment it's count in the character array.

We print the histogram at the end, by looping through the characters of the
array, printing the character and then printing `*` for number of times that
character had occurred.


---- 

This document was updated on |today|
