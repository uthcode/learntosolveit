====================================
Exercise 5.17 - Sorting with options
====================================

Question
========

Add a field-searching capability, so sorting may bee done on fields within
lines, each field sorted according to an independent set of options. (The index
for this book was sorted with -df for the index category and -n for the page
numbers.)

.. literalinclude:: cprogs/ex_5.17_sortdfnr-withoption.c
   :language: c
   :tab-width: 4

Explanation
===========

This program is an enhanced version of the previous sort program.
The main difference is that it can sort text based on specific fields (portions) within each line, rather than just sorting entire lines. This is particularly useful for sorting structured data like tables or indexes.

Key differences from the previous version:

Added field handling with two new parameters:

+pos1: Specifies where to start looking in each line (starting position)
-pos2: Specifies where to stop looking in each line (ending position)


Example usage:

# Original data (index with page numbers):
Arrays, dynamic 125
Arrays, initialization 89
Arrays, multidimensional 110

::

    sort -df +0 -2 -n +2

    # Using an example line: "Arrays, dynamic 125"


Let's separate each part:

* -df: These are sorting options
* -d: Directory order (only considers letters, numbers, and spaces)
* -f: Fold case (treats uppercase and lowercase as the same)


::

    +0 -2: This specifies the first field to sort by


* +0: Start from position 0 (beginning of line)
* -2: Stop before position 2 (in this case, the text portion)

So this would look at "Arrays, dynamic"


::

    -n +2: This specifies the second field to sort by

* -n: Use numeric sorting
* +2: Start from position 2 (where the numbers are)
* So this would look at "125"
