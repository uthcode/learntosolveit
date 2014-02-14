======================================================================
Exercise 2.5 - return the first location in the string s1 comparing s2
======================================================================

Question
========

Write the function any(s1,s2), which returns the first location in a string s1 where any
character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library
function strpbrk does the same job but returns a pointer to the location.)

.. literalinclude:: ../../languages/cprogs/Ex_2.5_any.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_2.5_any.c
   :language: c
   :codesite: ideone

Explaination
============


The important part of the program is the function `any` which takes two strings `s1` and `s2` and tries to find if any character in `s2` matches `s1`. We set a **flag**, `check_next_char` which is toggled to **0** if we find the match, otherwise we have it as 1.

The first for loop iterates through all the characters in s1 while the condition `check_next_char` is 1. In the second for loop, if we find that a char in s2 matches s1, that is `s2[j] == s1[i]` and s2 has not reached EOL, then we set check_next_char to 0. That is we found a match at **i** and we return that.

If we dont find a match in s2, we increment i and take the next character from s1. If dont find a match at all, then we return -1.
