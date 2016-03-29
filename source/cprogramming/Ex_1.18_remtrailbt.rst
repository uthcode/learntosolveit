===============================================
Exercise 1.18 - Remove trailing blanks and tabs
===============================================

Question
--------


Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.18_remtrailbt.c
   :language: c
   :tab-width: 2


.. runcode:: ../../languages/cprogs/Ex_1.18_remtrailbt.c
   :language: c
   :codesite: ideone


Explanation
===========

In the removetrail function, we go to the very end of the line and the trace
back to the find the character which is not a space, tab and then replace it
with \0. This eliminates the trailing blanks in a line. For the empty lines
whose length is 0, we simply skip that from output and thus removing it.



.. seealso::

   * :c-suggest-improve:`Ex_1.18_remtrailbt.c`
   * :c-better-explain:`Ex_1.18_remtrailbt.rst`

