===========================
Section 1.5.3 Line Counting
===========================

Program
=======

.. literalinclude:: cprogs/sec_1.5.3_line_counting.c
   :language: c

Explanation
===========

This Program counts input lines. The program does that counting by setting a
variable nl to 0 in the beginning.  As the program one character at a time in
the while loop  ((c = getchar()) != EOF) till the EOF.  If the character is
newline character '\n' the number of lines variable is incremented, ++nl. At the
end, the number of lines, nl, is printed.

----

This document was updated on |today|
