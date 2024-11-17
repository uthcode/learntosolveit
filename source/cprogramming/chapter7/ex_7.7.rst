==================================================
Exercise 7.7 - Pattern matching program with files
==================================================

Question
========

Modify the pattern finding program of Chapter 5 to take its input from a set of
named files or, if no files are named as arguments, from the standard input.
Should the file name be printed when a matching line is found?

.. literalinclude:: cprogs/ex_7.7.c
   :language: c
   :tab-width: 4

Explanation
===========

This program searches for a pattern `char pattern[] = "ould";`` in the given input line.
The idea of this program is to take the input from a file.




