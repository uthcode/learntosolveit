=========================
5.17 Sorting with options
=========================

Question
========

Add a field-searching capability, so sorting may bee done on fields within
lines, each field sorted according to an independent set of options. (The index
for this book was sorted with -df for the index category and -n for the page
numbers.)

.. coderun:: cprogs/ex_5.17_sortdfnr-withoption.c
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

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20sort%20with%20combined%20-d%20-f%20-n%20-r%20options%20via%20flag%20variables%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20%2Alines%5B3%5D%20%3D%20%7B%22banana%22%2C%20%22apple%22%2C%20%22cherry%22%7D%3B%0A%20%20%20%20int%20reverse%20%3D%201%3B%20%20%2F%2A%20-r%20flag%3A%20sort%20descending%20%2A%2F%0A%20%20%20%20int%20i%2C%20j%3B%0A%20%20%20%20char%20%2Atmp%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%202%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20for%20%28j%20%3D%20i%2B1%3B%20j%20%3C%203%3B%20j%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20int%20cmp%20%3D%20strcmp%28lines%5Bi%5D%2C%20lines%5Bj%5D%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20if%20%28reverse%29%20cmp%20%3D%20-cmp%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20if%20%28cmp%20%3E%200%29%20%7B%20tmp%20%3D%20lines%5Bi%5D%3B%20lines%5Bi%5D%20%3D%20lines%5Bj%5D%3B%20lines%5Bj%5D%20%3D%20tmp%3B%20%7D%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%203%3B%20i%2B%2B%29%20printf%28%22%25s%5Cn%22%2C%20lines%5Bi%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
