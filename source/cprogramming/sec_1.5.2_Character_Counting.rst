================================
Section 1.5.2 Character Counting
================================


Program
-------


.. literalinclude:: ../../languages/cprogs/sec_1.5.2_Character_Counting.c
   :language: c
   :tab-width: 4
   
.. runcode:: ../../languages/cprogs/sec_1.5.2_Character_Counting.c
   :language: c
   :codesite: ideone
 
Explanation
-----------

In this program we are going to count the number of characters present in the
input. The program does the counting by setting nc to 0 in the beginning. As the
program enters while loop condition (getchar() != EOF).  When nc hits end of the
document it prints the number of characters in the file.

.. seealso::

   * :c-suggest-improve:`sec_1.5.2_Character_Counting.c`
   * :c-better-explain:`sec_1.5.2_Character_Counting.rst`

---- 

This document was updated on |today|
