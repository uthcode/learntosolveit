============================
1.11 Test Word count program
============================

Question
========

How would you test the word count program? What kinds of input
are most likely to uncover bugs if there are any?

Program
=======

.. literalinclude:: cprogs/sec_1.5.4_word_counting.c
   :language: c

Explanation
===========

Testing the word count program involves, giving three kinds of inputs.

1. Valid Inputs.
2. Boundary Condition Inputs.
3. Invalid Inputs.

For Valid Inputs, it could be any stream of space separate text. It has valid
space, newline and tab characters. For Boundary conditions, a file entirely
consisting of \n, or a file entirely consisting of \t character or a empty file.

For invalid Inputs, an unclosed file which does not have EOF, which is tricky to
provide can be given to this program. A unicode character file can be given and
see if getchar() handles it properly. We tested it and it works.
Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20IN%2FOUT%20state%20machine%20counts%20lines%2C%20words%2C%20chars%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23define%20IN%20%201%0A%23define%20OUT%200%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22one%20two%5Cn%22%3B%0A%20%20%20%20int%20nl%20%3D%200%2C%20nw%20%3D%200%2C%20nc%20%3D%200%2C%20state%20%3D%20OUT%2C%20i%20%3D%200%2C%20c%3B%0A%20%20%20%20while%20%28%28c%20%3D%20%28unsigned%20char%29s%5Bi%2B%2B%5D%29%29%20%7B%0A%20%20%20%20%20%20%20%20%2B%2Bnc%3B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%5Cn%27%29%20%2B%2Bnl%3B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%20%27%20%7C%7C%20c%20%3D%3D%20%27%5Cn%27%20%7C%7C%20c%20%3D%3D%20%27%5Ct%27%29%20state%20%3D%20OUT%3B%0A%20%20%20%20%20%20%20%20else%20if%20%28state%20%3D%3D%20OUT%29%20%7B%20state%20%3D%20IN%3B%20%2B%2Bnw%3B%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22%25d%20%25d%20%25d%5Cn%22%2C%20nl%2C%20nw%2C%20nc%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
