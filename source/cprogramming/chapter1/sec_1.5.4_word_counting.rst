===================
1.5.4 Word Counting
===================


Program
=======

.. coderun:: cprogs/sec_1.5.4_word_counting.c
   :language: c

Explanation
===========

We need to count the number of characters, the number of words and the newlines
in the program. We store the characters in a variable `c`, it's count in nc, the
count of newlines in `nl` and the number of words in `nw`. In order to count the
words, the trick is to know when we enter the word and when we exit the word.
This  is kept track by a `state` variable.

We start with OUTSIDE a word, if we hit a whitespace (' ', \t or \n), we say, we
are outside the word (`state` = OUT). When we read a character again which is
not a whitespace and if were in OUT state earlier, we move to IN state (that is
we saw a new word) and we increment `nw`. For every character we read, we
increment `nc` and for every `\n` we read, we increment `nl`.  The program in
the end prints, the *nl*, *nw* and *nc*.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20count%20lines%2C%20words%2C%20characters%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23define%20IN%201%0A%23define%20OUT%200%0Aint%20main%28%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22one%20two%5Cn%22%3B%0A%20%20%20%20int%20nl%20%3D%200%2C%20nw%20%3D%200%2C%20nc%20%3D%200%2C%20state%20%3D%20OUT%2C%20i%20%3D%200%2C%20c%3B%0A%20%20%20%20while%20%28%28c%20%3D%20%28int%29%28unsigned%20char%29s%5Bi%2B%2B%5D%29%29%20%7B%0A%20%20%20%20%20%20%20%20%2B%2Bnc%3B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%5Cn%27%29%20%2B%2Bnl%3B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%20%27%20%7C%7C%20c%20%3D%3D%20%27%5Cn%27%20%7C%7C%20c%20%3D%3D%20%27%5Ct%27%29%20state%20%3D%20OUT%3B%0A%20%20%20%20%20%20%20%20else%20if%20%28state%20%3D%3D%20OUT%29%20%7B%20state%20%3D%20IN%3B%20%2B%2Bnw%3B%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22%25d%20%25d%20%25d%5Cn%22%2C%20nl%2C%20nw%2C%20nc%29%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
