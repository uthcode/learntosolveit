====================================
1.18 Remove trailing blanks and tabs
====================================

Question
--------


Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.

Solution
--------

.. coderun:: cprogs/ex_1.18_remtrailbt.c
   :language: c

Explanation
===========

In the remove_trail function, we go to the very end of the line and the trace
back to the find the character which is not a space, tab and then replace it
with \0. This eliminates the trailing blanks in a line. For the empty lines
whose length is 0, we simply skip that from output and thus removing it.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20remove%20trailing%20blanks%20by%20scanning%20backwards%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22hi%20%20%20%22%3B%0A%20%20%20%20int%20i%20%3D%200%2C%20end%3B%0A%20%20%20%20while%20%28s%5Bi%5D%29%20i%2B%2B%3B%0A%20%20%20%20end%20%3D%20i%20-%201%3B%0A%20%20%20%20while%20%28end%20%3E%3D%200%20%26%26%20%28s%5Bend%5D%20%3D%3D%20%27%20%27%20%7C%7C%20s%5Bend%5D%20%3D%3D%20%27%5Ct%27%29%29%20end--%3B%0A%20%20%20%20s%5Bend%20%2B%201%5D%20%3D%20%27%5C0%27%3B%0A%20%20%20%20printf%28%22%27%25s%27%5Cn%22%2C%20s%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
