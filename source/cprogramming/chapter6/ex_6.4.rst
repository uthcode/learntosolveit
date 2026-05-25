=======================
6.4 Words and Frequency
=======================

Question
========

Write a program that prints the distinct words in its input sorted into
decreasing order of frequency of occurrence. Precede each word by its count.

.. literalinclude:: cprogs/ex_6.4.c
   :language: c
   :tab-width: 4

Explanation
===========

This program prints the distinct words in its input sorted into decreasing order of frequency of occurrence. Each word
is preceded by its count.

This works by creating a Tree with word and count, just like tnode.
Parse the tree and create a new tree with count and list of words in the node. Print the new tree in-order traversal.

::

    ab
    ab
    bc
    cd
    ef
    gh
    ab
    x
    Words and their frequencies:
    bc->1
    cd->1
    ef->1
    gh->1
    ab->3





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20word-frequency%20BST%20%E2%80%94%20each%20node%20stores%20word%20%2B%20count%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstring.h%3E%0Astruct%20wnode%20%7B%20char%20word%5B8%5D%3B%20int%20count%3B%20struct%20wnode%20%2Al%2C%20%2Ar%3B%20%7D%3B%0Astruct%20wnode%20%2Aadd%28struct%20wnode%20%2Ap%2C%20char%20%2Aw%29%20%7B%0A%20%20%20%20int%20c%3B%0A%20%20%20%20if%20%28%21p%29%20%7B%0A%20%20%20%20%20%20%20%20p%20%3D%20malloc%28sizeof%20%2Ap%29%3B%0A%20%20%20%20%20%20%20%20strncpy%28p-%3Eword%2C%20w%2C%207%29%3B%20p-%3Eword%5B7%5D%20%3D%200%3B%0A%20%20%20%20%20%20%20%20p-%3Ecount%20%3D%201%3B%20p-%3El%20%3D%20p-%3Er%20%3D%20NULL%3B%0A%20%20%20%20%7D%20else%20if%20%28%28c%20%3D%20strcmp%28w%2C%20p-%3Eword%29%29%20%3D%3D%200%29%20p-%3Ecount%2B%2B%3B%0A%20%20%20%20else%20if%20%28c%20%3C%200%29%20p-%3El%20%3D%20add%28p-%3El%2C%20w%29%3B%0A%20%20%20%20else%20%20%20%20%20%20%20%20%20%20%20%20p-%3Er%20%3D%20add%28p-%3Er%2C%20w%29%3B%0A%20%20%20%20return%20p%3B%0A%7D%0Avoid%20print%28struct%20wnode%20%2Ap%29%20%7B%0A%20%20%20%20if%20%28%21p%29%20return%3B%0A%20%20%20%20print%28p-%3El%29%3B%0A%20%20%20%20printf%28%22%25d%20%25s%5Cn%22%2C%20p-%3Ecount%2C%20p-%3Eword%29%3B%0A%20%20%20%20print%28p-%3Er%29%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20struct%20wnode%20%2Aroot%20%3D%20NULL%3B%0A%20%20%20%20char%20%2Awords%5B%5D%20%3D%20%7B%22hi%22%2C%22bye%22%2C%22hi%22%2C%22ok%22%2C%22bye%22%2C%22hi%22%7D%3B%0A%20%20%20%20int%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%206%3B%20i%2B%2B%29%20root%20%3D%20add%28root%2C%20words%5Bi%5D%29%3B%0A%20%20%20%20print%28root%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
