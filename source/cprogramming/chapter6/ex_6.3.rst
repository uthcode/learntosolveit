===============================
Exercise 6.3 - Cross Referencer
===============================

Question
========

Write a cross-referencer that prints a list of all words in a document, and for
each word, a list of the line numbers on which it occurs. Remove noise words
like ``the, and`` and so on.

.. literalinclude:: cprogs/ex_6.3.c
   :language: c
   :tab-width: 4

Explanation
===========

Here is an example execution of this program.

::

    [ec2-user@ip-172-32-32-162 learntosolveit]$ ./ex_6.3
    This is a
    cross reference
    word
    document
    creator
    lists words and their line numbers.
    Gets the word and puts their line numbers.

    Gets: [7]
    This: [1]
    and: [6, 7]
    creator: [5]
    cross: [2]
    document: [4]
    line: [6, 7]
    lists: [6]
    numbers: [6, 7]
    puts: [7]
    reference: [2]
    word: [3, 7]
    words: [6]
