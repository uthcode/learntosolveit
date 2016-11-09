===============================================================
Exercise 5.5 - simple versions of strncpy, strncat, and strncmp
===============================================================

Question
========

Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings.

.. literalinclude:: ../../languages/cprogs/Ex_5.5_strncpy.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_5.5_strncpy.c
   :language: c
   :codesite: ideone

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




.. seealso::

   * :c-suggest-improve:`Ex_5.5_strncpy.c`
   * :c-better-explain:`Ex_5.5_strncpy.rst`
