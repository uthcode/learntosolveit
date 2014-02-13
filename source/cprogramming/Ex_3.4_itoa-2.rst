======================================================
Exercise 3.4 - itoa to handle largest negative integer
======================================================

Question
========

In a two's complement number representation, our version of itoa does not handle the largest negative number, 
that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, 
regardless of the machine on which it runs.

The previous version of itoa was this::

    void itoa() {
    
    }

.. literalinclude:: ../../languages/cprogs/Ex_3.4_itoa-2.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_3.4_itoa-2.c
   :language: c
   :codesite: ideone

Explaination
============



.. seealso::

   * :c-suggest-improve:`Ex_3.4_itoa-2.c`
   * :c-better-explain:`Ex_3.4_itoa-2.rst`
