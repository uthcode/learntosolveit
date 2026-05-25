=====================
1.19 reverse a string
=====================

Question
--------


Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time.

Solution
--------

.. coderun:: cprogs/ex_1.19_reversestr.c
   :language: c


Explanation
===========

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


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20reverse%20a%20string%20in-place%20using%20two%20pointers%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22hello%22%3B%0A%20%20%20%20int%20i%20%3D%200%2C%20j%2C%20len%3B%0A%20%20%20%20char%20temp%3B%0A%20%20%20%20while%20%28s%5Bi%5D%29%20i%2B%2B%3B%0A%20%20%20%20len%20%3D%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%2C%20j%20%3D%20len-1%3B%20i%20%3C%20j%3B%20i%2B%2B%2C%20j--%29%20%7B%0A%20%20%20%20%20%20%20%20temp%20%3D%20s%5Bi%5D%3B%20s%5Bi%5D%20%3D%20s%5Bj%5D%3B%20s%5Bj%5D%20%3D%20temp%3B%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22%25s%5Cn%22%2C%20s%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
