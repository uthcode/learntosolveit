==================================
Exercise 6.4 - Words and Frequency
==================================

Question
========

Write a program that prints the distinct words in its input sorted into
decreasing order of frequency of occurrence. Precede each word by its count.

.. literalinclude:: cprogs/ex_6.4.c
   :language: c
   :tab-width: 4

Explanation
===========

This program prints the distinct words in its input sorted into decreasing order of frequency of occurrence. Each word
is preceded by its count.

This works by creating a Tree with word and count, just like tnode.
Parse the tree and create a new tree with count and list of words in the node. Print the new tree in-order traversal.

::

    ab
    ab
    bc
    cd
    ef
    gh
    ab
    x
    Words and their frequencies:
    bc->1
    cd->1
    ef->1
    gh->1
    ab->3




