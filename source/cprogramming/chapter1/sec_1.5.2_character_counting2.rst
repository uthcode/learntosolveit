=================================
Section 1.5.2 Character Counting2
=================================


Program
-------


.. literalinclude:: cprogs/sec_1.5.2_character_counting2.c
   :language: c


Explanation
-----------

In this program we are going to count the number of characters present in the
input. The program does the counting by setting nc to 0 in the beginning. As the
program enters for loop condition (nc = 0; getchar() != EOF; ++nc).  When nc
hits end of the document it prints the number of characters in the file.


----

This document was updated on |today|
