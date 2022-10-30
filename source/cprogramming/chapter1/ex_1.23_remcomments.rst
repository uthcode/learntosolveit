================================================
Exercise 1.23 - Remove comments from a C program
================================================

Question
--------


Write a program to remove all comments from a C program. Don't forget to handle
quoted strings and character constants properly. C comments don't nest.


Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.23_remcomments.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_1.23_remcomments.c
   :language: c
   :codesite: ideone

Explanation
===========

If two subsequent characters start with `/` and `*`, we say we are in-comment,
If we find two characters which are `/` and `/`, we will print the first
character and start treating the second `/` as the possible start of comment. In
the same manner, if we encouter a single quote or a double quote character, then
we understand we are inside a quoted string, so we putchar everything before we
find the matching character again. Within a quoted string, if we encouter a
special character, then we try to read them literally as two characters and
print them.

If / is followed by any other character, we simply print them.



..  seealso::

   * :c-suggest-improve:`Ex_1.23_remcomments.c`
   * :c-better-explain:`Ex_1.23_remcomments.rst`
