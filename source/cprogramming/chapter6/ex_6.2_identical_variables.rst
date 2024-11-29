==================================
Exercise 6.2 - Identical Variables
==================================


Question
========

Write a program that reads a C program and prints in alphabetical order each
group of variable names that are identical in the first 6 characters, but
different somewhere thereafter. Don't count words within strings and comments.
Make 6 a parameter that can be set from the command line.

.. literalinclude:: cprogs/ex_6.2_identical_variables.c
   :language: c
   :tab-width: 4

Explanation
===========

This program reads a C program and groups similar list of variable names as similar words list.
It parses the C program and stores the variables names in a binary tree, then constructs a similar word list which have
a common prefix length.


