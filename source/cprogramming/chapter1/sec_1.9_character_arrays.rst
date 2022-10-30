============================
Section 1.9 Character Arrays
============================


Program
=======

.. literalinclude:: cprogs/sec_1.9_character_arrays.c
   :language: c

Explanation
===========

In C, strings are nothing but a character arrays which end with a special
character `\0`. In this program, we declare character arrays `char line[]`  in
the geline function and then `char to[]` and `char from[]` in the copy function.
Since arrays are passed by **reference**, so when we send `to` and `from` the
calling program, the function copies the contents to the `to` array and we are
reference the `to` array further from the main program itself. This is
demonstrated by copying line to the longest and then printing the longest in the
main program.

