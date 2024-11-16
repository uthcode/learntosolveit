===============================================================
Exercise 5.16 - -d makes comparison on letters, numbers, blanks
===============================================================

Question
========

Add the -d (``directory order``) option, which makes comparisons only on
letters, numbers and blanks. Make sure it works in conjunction with -f.

.. literalinclude:: cprogs/ex_5.16_sort_dfnr.c
   :language: c
   :tab-width: 4


Explanation
===========

This is a command-line sorting program that can sort text lines in different ways based on various options.
The `-d` flag sorts the lines of input in the directory order, that is ignoring punctuation marks.
The `-f` folds the input, that is, it does a case insensitive comparison of lower case and upper case lines.


::

     ./ex_5.16_sort_dfnr -d
    something-anotherthing
    some-thing
    another-thing
    one!
    once
    ^D
    another-thing
    once
    one!
    some-thing
    something-anotherthing


::

    ./ex_5.16_sort_dfnr -df
    Apple
    apple
    apple-pie
    Carrot-Cake


    apple
    Apple
    apple-pie
    Carrot-Cake



