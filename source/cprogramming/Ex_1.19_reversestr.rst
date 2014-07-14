================================
Exercise 1.19 - reverse a string
================================

Question
--------


Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time.

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.19_reversestr.c
   :language: c
   :tab-width: 2


.. runcode:: ../../languages/cprogs/Ex_1.19_reversestr.c
   :language: c
   :codesite: ideone

Explaination
------------

A string in C is a character array which ends in `\0`. **getline** is a function
in our program, which reads one character at a time using getchar and stores it
in a character array called s[] and it returns the length of the array. We call
the reverse function on our line. In the reverse function, we calculate the
length of the line minus `\0` and `\n` if that is present. This determines the
ultimate printable characters in the line from where we have to reverse.

We have to two incides, j=0 and i the last printable character and run through
the program of swapping those characters till  `j < i`. 
This reverses the contents of our string.

The crux of the program is this::

          j = 0;

      while(j < i)
      {
        temp = rline[j];
        rline[j] = rline[i];
        rline[i] = temp;
        --i;
        ++j;
      }

.. git_changelog::  

.. seealso::

   * :c-suggest-improve:`Ex_1.19_reversestr.c`
   * :c-better-explain:`Ex_1.19_reversestr.rst`

