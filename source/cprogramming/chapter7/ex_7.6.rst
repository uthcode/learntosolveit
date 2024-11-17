================================
Exercise 7.6 - Compare Two files
================================

Question
========

Write a program to compare two files, printing the first line where they differ.

.. literalinclude:: cprogs/ex_7.6.c
   :language: c
   :tab-width: 4

Explanation
===========


This program reads two files using two file pointers, get one character at a time from each file and compares them,
and if they are not same, prints their differences.

::

        if (f1 != f2) {
            putchar(f1);
            putchar(f2);
            break;
        }


