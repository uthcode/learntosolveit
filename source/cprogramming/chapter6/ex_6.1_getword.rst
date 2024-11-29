======================
Exercise 6.1 - getword
======================

Question
========

Our version of getword does not properly handle underscores, string constants,
comments, or preprocessor control lines. Write a better version.

.. literalinclude:: cprogs/ex_6.1_getword.c
   :language: c
   :tab-width: 4

This is program from Section 6.3  implementing getword.

.. literalinclude:: cprogs/sec_6.3_getword.c
   :language: c
   :tab-width: 4

Explanation
===========

This program identifies the keywords in the given input.

::

    $ ./ex_6.1_getword
    this is a short sentence.
       1 short


