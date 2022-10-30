=========================================
Section 1.10 External Variables and Scope
=========================================

Program
=======

.. literalinclude:: cprogs/sec_1.10_external_variables.c
   :language: c

Explanation
===========

This program is same as finding the length of the longest line. The special
thing here is we use external variables declared outside of any functions in the
program and reference them within the functions by using the type **extern**.
Here we see the integer max, strings line and longest declared outside of the
main function, and those variables are referenced using **extern** type in main,
getline and in copy function so that all these functions act upon the same
variable. That is the reason, unlike the previous programs, we do not send the
line and the longest as arguments to getline and copy, and neither we have to
return the length from getline, because sharing of those is accomplished by
sharing of the variable themselves.

