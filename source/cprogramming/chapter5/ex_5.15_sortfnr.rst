==================================================
Exercise 5.15 - fold upper and lower case together
==================================================

Question
========

Add the option -f to fold upper and lower case together, so that case
distinctions are not made during sorting; for example, a and A compare equal.

.. literalinclude:: cprogs/ex_5.15_sortfnr.c
   :language: c
   :tab-width: 4


Explanation
===========


This is a sort function, which sorts the given input lines. But this function adds a flag `-f` which introduces case insensitive folding.

.. raw::

    ./ex_5.15_sortfnr -f
    hello
    Hello
    Apple
    Apple
    Hello
    hello






