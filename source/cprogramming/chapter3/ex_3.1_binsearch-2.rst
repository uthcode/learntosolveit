===========================================================
3.1 Binsearch function, writing minimum tests inside a loop
===========================================================

Question
========

Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the
loop and measure the difference in runtime.

.. coderun:: cprogs/ex_3.1_binsearch-2.c
   :language: c
   :tab-width: 4

Explanation
===========

The program demonstrates a binsearch function which takes element (x) to search
for, an array of integers and the length of the array as arguments.

The program determines the position of the element(x) by doing a binary search.
Binary search can only be used for sorted arrays. Program compares search
element (x) with mid element of the given array. If mid element is greater than
search element then search continues among the rest of the elements towards
left of current mid element. Search continues in similar fashion. If found,
program returns the position of search element in the array.

In the example above search element is 9. Program returns 4 which is the
position of search element

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20binary%20search%20%E2%80%94%20compute%20mid%20first%2C%20then%20loop%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20binsearch%28int%20x%2C%20int%20v%5B%5D%2C%20int%20n%29%20%7B%0A%20%20%20%20int%20low%20%3D%200%2C%20high%20%3D%20n%20-%201%2C%20mid%3B%0A%20%20%20%20mid%20%3D%20%28low%20%2B%20high%29%20%2F%202%3B%0A%20%20%20%20while%20%28low%20%3C%20high%20%26%26%20x%20%21%3D%20v%5Bmid%5D%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28x%20%3E%20v%5Bmid%5D%29%20low%20%3D%20mid%20%2B%201%3B%0A%20%20%20%20%20%20%20%20else%20high%20%3D%20mid%20-%201%3B%0A%20%20%20%20%20%20%20%20mid%20%3D%20%28low%20%2B%20high%29%20%2F%202%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20%28x%20%3D%3D%20v%5Bmid%5D%29%20%3F%20mid%20%3A%20-1%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20arr%5B%5D%20%3D%20%7B2%2C%204%2C%206%2C%209%2C%2015%7D%3B%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20binsearch%289%2C%20arr%2C%205%29%29%3B%20%20%20%2F%2A%20found%20at%20index%203%20%2A%2F%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20binsearch%285%2C%20arr%2C%205%29%29%3B%20%20%20%2F%2A%20not%20found%3A%20-1%20%2A%2F%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
