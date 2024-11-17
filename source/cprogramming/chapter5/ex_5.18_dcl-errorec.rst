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

The program has an errmsg function that is called whenever an error is detected during parsing.
The dcl and dirdcl functions, which are responsible for parsing the declarator, continue parsing even if an error is encountered.

