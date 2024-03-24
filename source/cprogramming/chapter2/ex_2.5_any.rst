======================================================================
Exercise 2.5 - return the first location in the string s1 comparing s2
======================================================================

Question
========

Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no
characters from s2. (The standard library function strpbrk does the same job but
returns a pointer to the location.)

.. literalinclude:: cprogs/ex_2.5_any.c
   :language: c

Explanation
===========


The important part of the program is the function `any` which takes two strings
`s1` and `s2` and tries to find if any character in `s2` matches `s1`. We set a
**flag**, `check_next_char` which is toggled to **0** if we find the match,
otherwise we have it as 1.

The first for loop iterates through all the characters in s1 while the condition
`check_next_char` is 1. In the second for loop, if we find that a char in s2
matches s1, that is `s2[j] == s1[i]` and s2 has not reached EOL, then we set
check_next_char to 0. That is we found a match at **i** and we return that.

If we dont find a match in s2, we increment i and take the next character from
s1. If dont find a match at all, then we return -1.


Visualization
=============

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%0A%23define%20MAXLINE%201000%0A%0Aint%20any%28char%20s1%5B%5D,%20const%20char%20s2%5B%5D%29%3B%0A%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s1%5B%5D%20%3D%20%7B'X',%20'Y',%20'L',%20'O'%7D%3B%0A%20%20%20%20char%20s2%5B%5D%20%3D%20%7B'O',%20'z'%7D%3B%0A%0A%20%20%20%20int%20val%3B%0A%0A%20%20%20%20val%20%3D%20any%28s1,%20s2%29%3B%0A%0A%20%20%20%20printf%28%22%25d%22,%20val%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D%0A%0Aint%20any%28char%20s1%5B%5D,%20const%20char%20s2%5B%5D%29%20%7B%0A%20%20%20%20int%20i,%20j%3B%0A%0A%20%20%20%20for%20%28i%20%3D%200%3B%20s1%5Bi%5D%20!%3D%20'%5C0'%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20%20%20%20%20//%20iterate%20through%20s2%20while%20trying%20to%20find%20matching%20character%20from%20s1%0A%20%20%20%20%20%20%20%20for%20%28j%20%3D%200%3B%20%28s1%5Bi%5D%20!%3D%20s2%5Bj%5D%29%20%26%26%20s2%5Bj%5D%20!%3D%20'%5C0'%3B%20%2B%2Bj%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%3B%20//%20continue%0A%0A%20%20%20%20%20%20%20%20if%20%28s2%5Bj%5D%20!%3D%20'%5C0'%20%26%26%20s2%5Bj%5D%20!%3D%20'%5Cn'%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20//%20Due%20to%20custom%20getline%20function,%20we%20need%20to%20check%20for%20newline%0A%20%20%20%20%20%20%20%20%20%20%20%20return%20i%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%20-1%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>

Try It Out
==========

.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex25any?embed=true"></iframe>
