==============================================================
Exercise 3.3 - expand short hand notation in s1 into string s2
==============================================================

Question
========

Write a function expand(s1,s2) that expands shorthand notations like a-z in the
string s1 into the equivalent complete list abc...xyz in s2. Allow for letters
of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9
and -a-z. Arrange that a leading or trailing -is taken literally.

.. literalinclude:: ../../languages/cprogs/Ex_3.3_expand.c
   :language: c
   :tab-width: 4
   

.. runcode:: ../../languages/cprogs/Ex_3.3_expand.c
   :language: c
   :codesite: ideone
   

Explaination
============

Here we expand the strings like a-z from s1 into an expanded form in s2. We
utilize the ascii table property that the second character is higher than the
first character and it is incremental.

In the outer while loop, we get the character in c, and then check if the next
character is `-` and character beyond that (i+1) is greater than c. With this
check, we ascertain that we are in a range like `a-z`.

To expand the range, we keep incrementing the character in **c**, till it hits
the end character, storing all the characters in s2.

s2 will now have the expanded string.



.. seealso::

   * :c-suggest-improve:`Ex_3.3_expand.c`
   * :c-better-explain:`Ex_3.3_expand.rst`
