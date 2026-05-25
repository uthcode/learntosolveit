===========
6.1 getword
===========

Question
========

Our version of getword does not properly handle underscores, string constants,
comments, or preprocessor control lines. Write a better version.

.. coderun:: cprogs/ex_6.1_getword.c
   :language: c
   :tab-width: 4

This is program from Section 6.3  implementing getword.

.. literalinclude:: cprogs/sec_6.3_getword.c
   :language: c
   :tab-width: 4

Explanation
===========

This program identifies the keywords in the given input.

::

    $ ./ex_6.1_getword
    this is a short sentence.
       1 short



Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20count%20keyword%20occurrences%20using%20struct%20array%20%2B%20binary%20search%20%2A%2F%0A%23include%20%3Cstring.h%3E%0A%23include%20%3Cstdio.h%3E%0Astruct%20key%20%7B%20char%20%2Aword%3B%20int%20count%3B%20%7D%20keytab%5B%5D%20%3D%20%7B%0A%20%20%20%20%7B%22for%22%2C%200%7D%2C%20%7B%22if%22%2C%200%7D%2C%20%7B%22while%22%2C%200%7D%0A%7D%3B%0A%23define%20NKEYS%203%0Aint%20binsearch%28char%20%2Aword%29%20%7B%0A%20%20%20%20int%20cond%2C%20low%20%3D%200%2C%20high%20%3D%20NKEYS%20-%201%2C%20mid%3B%0A%20%20%20%20while%20%28low%20%3C%3D%20high%29%20%7B%0A%20%20%20%20%20%20%20%20mid%20%3D%20%28low%20%2B%20high%29%20%2F%202%3B%0A%20%20%20%20%20%20%20%20if%20%28%28cond%20%3D%20strcmp%28word%2C%20keytab%5Bmid%5D.word%29%29%20%3C%200%29%20high%20%3D%20mid%20-%201%3B%0A%20%20%20%20%20%20%20%20else%20if%20%28cond%20%3E%200%29%20low%20%3D%20mid%20%2B%201%3B%0A%20%20%20%20%20%20%20%20else%20return%20mid%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20-1%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20%2Awords%5B%5D%20%3D%20%7B%22if%22%2C%20%22for%22%2C%20%22if%22%2C%20%22while%22%7D%3B%0A%20%20%20%20int%20i%2C%20n%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%204%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20if%20%28%28n%20%3D%20binsearch%28words%5Bi%5D%29%29%20%3E%3D%200%29%20keytab%5Bn%5D.count%2B%2B%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20NKEYS%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20if%20%28keytab%5Bi%5D.count%20%3E%200%29%20printf%28%22%254d%20%25s%5Cn%22%2C%20keytab%5Bi%5D.count%2C%20keytab%5Bi%5D.word%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
