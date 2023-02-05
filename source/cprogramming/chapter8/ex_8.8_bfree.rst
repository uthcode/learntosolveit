=========================================
Exercise 8.8 - bfree maintained by malloc
=========================================

Question
========

Write a routine bfree(p,n) that will free any arbitrary block p of n characters
into the free list maintained by malloc and free. By using bfree, a user can add
a static or external array to the free list at any time.

.. literalinclude:: cprogs/ex_8.8_bfree.c
   :language: c


Explanation
===========

