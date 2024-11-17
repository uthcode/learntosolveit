=========================================
Exercise 5.18 - recover from input errors
=========================================

Question
========

Make dcl recover from input errors.

.. literalinclude:: cprogs/ex_5.18_dcl-errorec.c
   :language: c
   :tab-width: 4

Explanation
===========

This program is a recursive descent parser that converts C-style declarations into English descriptions.
The program takes a C declaration as input and converts it into a more readable English description. For example:

::

    ./ex_5.18_dcl-errorec
    char *str[]
    str  arg[] of pointer to char


The program has an errmsg function that is called whenever an error is detected during parsing.
The dcl and dirdcl functions, which are responsible for parsing the declarator, continue parsing even if an error is encountered.

