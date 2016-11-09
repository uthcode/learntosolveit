======================================================
Exercise 3.4 - itoa to handle largest negative integer
======================================================

Question
========

In a two's complement number representation, our version of itoa does not handle
the largest negative number,  that is, the value of n equal to -(2wordsize-1).
Explain why not. Modify it to print that value correctly,  regardless of the
machine on which it runs.

The previous version of itoa was this::

    void itoa() {
    
    }

.. literalinclude:: ../../languages/cprogs/Ex_3.4_itoa-2.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_3.4_itoa-2.c
   :language: c
   :codesite: ideone

Explanation
===========

In this version of itoa, which involves a largest negative number, we first
store the number itself in an integer called sign. Then get numbers from
unittest by doing `n%10`, get the unsigned number by doing a `abs` value and get
character by adding it to `0`.

Thus we go about converting each digit starting from unit place to a character.
Once this process is over. We check if we were converting negative number, by
checking if the sign is less than 0, if it was, we add a `-` to the string.

And then we do a simple `reverse` of the string to get our `itoa`.



.. seealso::

   * :c-suggest-improve:`Ex_3.4_itoa-2.c`
   * :c-better-explain:`Ex_3.4_itoa-2.rst`
