====================
6.3 Cross Referencer
====================

Question
========

Write a cross-referencer that prints a list of all words in a document, and for
each word, a list of the line numbers on which it occurs. Remove noise words
like ``the, and`` and so on.

.. coderun:: cprogs/ex_6.3.c
   :language: c
   :tab-width: 4

Explanation
===========

This program is a cross-referencer that prints a list of all words in a document.

1. Create a binary tree that will contain words and structure with lines on which words occur.
2. Check if the word is noisy with binary search.
3. Print the words and lines.



Here is an example execution of this program.

::

    [ec2-user@ip-172-32-32-162 learntosolveit]$ ./ex_6.3
    This is a
    cross reference
    word
    document
    creator
    lists words and their line numbers.
    Gets the word and puts their line numbers.

    Gets: [7]
    This: [1]
    and: [6, 7]
    creator: [5]
    cross: [2]
    document: [4]
    line: [6, 7]
    lists: [6]
    numbers: [6, 7]
    puts: [7]
    reference: [2]
    word: [3, 7]
    words: [6]

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20cross-reference%20%E2%80%94%20binary%20tree%20of%20words%20with%20occurrence%20counts%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstring.h%3E%0Astruct%20tnode%20%7B%20char%20%2Aword%3B%20int%20count%3B%20struct%20tnode%20%2Aleft%2C%20%2Aright%3B%20%7D%3B%0Astruct%20tnode%20%2Aaddtree%28struct%20tnode%20%2Ap%2C%20char%20%2Aw%29%20%7B%0A%20%20%20%20int%20cond%3B%0A%20%20%20%20if%20%28%21p%29%20%7B%0A%20%20%20%20%20%20%20%20p%20%3D%20malloc%28sizeof%28struct%20tnode%29%29%3B%0A%20%20%20%20%20%20%20%20p-%3Eword%20%3D%20strdup%28w%29%3B%20p-%3Ecount%20%3D%201%3B%20p-%3Eleft%20%3D%20p-%3Eright%20%3D%20NULL%3B%0A%20%20%20%20%7D%20else%20if%20%28%28cond%20%3D%20strcmp%28w%2C%20p-%3Eword%29%29%20%3C%200%29%20p-%3Eleft%20%20%3D%20addtree%28p-%3Eleft%2C%20%20w%29%3B%0A%20%20%20%20else%20if%20%28cond%20%3E%200%29%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20p-%3Eright%20%3D%20addtree%28p-%3Eright%2C%20w%29%3B%0A%20%20%20%20else%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20p-%3Ecount%2B%2B%3B%0A%20%20%20%20return%20p%3B%0A%7D%0Avoid%20treeprint%28struct%20tnode%20%2Ap%29%20%7B%0A%20%20%20%20if%20%28p%29%20%7B%20treeprint%28p-%3Eleft%29%3B%20printf%28%22%254d%20%25s%5Cn%22%2C%20p-%3Ecount%2C%20p-%3Eword%29%3B%20treeprint%28p-%3Eright%29%3B%20%7D%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20struct%20tnode%20%2Aroot%20%3D%20NULL%3B%0A%20%20%20%20char%20%2Awords%5B%5D%20%3D%20%7B%22main%22%2C%20%22int%22%2C%20%22main%22%2C%20%22return%22%7D%3B%0A%20%20%20%20int%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%204%3B%20i%2B%2B%29%20root%20%3D%20addtree%28root%2C%20words%5Bi%5D%29%3B%0A%20%20%20%20treeprint%28root%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
