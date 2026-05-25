====================================================
5.5 simple versions of strncpy, strncat, and strncmp
====================================================

Question
========

Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings.

.. coderun:: cprogs/ex_5.5_strncpy.c
   :language: c
   :tab-width: 4


Explanation
===========

mystrlen assigns the address of s to p in `char *p = s` and then goes one
character at a time, till it reaches \0. When it is at the end of the word, it
subtracts the current address s with intial address p, which thus returns the
len of string.

mystrncpy copies n characters of source string to destination. It does this by
copying or overwriting one character a time from source to destination  and
keeps track of count n. When source is exhausted or n characters are copied, it
checks if there further characters in destination, if it exists, it goes past
them without over-writing and then closes the string by \0.

mystrncat, takes three arguments, str1, str2 and dest. It concatenates n
characters from str2 to str1 into a new string dest. It does this by copying all
characters from str1 to dest and then keeps a track of count n, and copies n
characters of str2 to dest. After copying n characters, it closes the dest
string by `\0` character.

mystrncmp, compares the lhs string with rhs string. It compares one character at
a time and as long as both characters are same, it keeps going and if the lhs is
exhaused before n characters are compared, it means we still satisfy the
criteria and we return 0. Otherwise, it returns the difference between lhs
character and rhs character, which will be 0 if they are equal,  negative if lhs
is smaller than rhs or positive value if lhs is greater than rhs.






Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20strncpy%20copies%20at%20most%20n%20chars%2C%20zero-pads%20if%20source%20is%20shorter%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Avoid%20mystrncpy%28char%20%2At%2C%20char%20%2As%2C%20int%20n%29%20%7B%0A%20%20%20%20for%20%28%3B%20n%20%3E%200%20%26%26%20%28%2At%20%3D%20%2As%29%20%21%3D%20%27%5C0%27%3B%20t%2B%2B%2C%20s%2B%2B%2C%20n--%29%3B%0A%20%20%20%20while%20%28n--%20%3E%200%29%20%2At%2B%2B%20%3D%20%27%5C0%27%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20dst%5B10%5D%3B%0A%20%20%20%20mystrncpy%28dst%2C%20%22hello%22%2C%203%29%3B%0A%20%20%20%20dst%5B3%5D%20%3D%20%27%5C0%27%3B%0A%20%20%20%20printf%28%22%25s%5Cn%22%2C%20dst%29%3B%20%20%2F%2A%20hel%20%2A%2F%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
