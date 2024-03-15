============================================================
Exercise 2.4 - Compare S1, S2 To Delete Same Character in S1
============================================================

Question
========

Write an alternative version of squeeze(s1,s2) that deletes each character in s1
that matches any character in the string s2.

.. literalinclude:: cprogs/ex_2.4_squeezess.c
   :language: c

Explanation
===========

Let's take the two inputs strings as:

.. code-block:: bash

    HelloWorld
    ol

Our desired output is

.. code-block:: bash

   HeWrd

This has removed the characters `o` and `l` from the first string. The way
squeeze works is, it take each character from the first string and if there is
no match found, stores it with a new index `k`. If there is a match found in
**s2**, it simply skips it.  The way it skips is realized by the following

.. code-block:: c

        for(j=0; (s1[i]!=s2[j]) && s2[j]!='\0' ;++j)
            ;
        if(s2[j]=='\0')
            s1[k++] = s1[i];

When the match is found **s1[i] == s2[j]** so our first for loop will **end**.
The second **if condtion** will fail too as s2 is not iterated till the end, so
we do not place the character in **s1[k++]** and we have successfully skipped
it.

Visualization
=============

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%0Avoid%20squeeze%28char%20s1%5B%5D,%20const%20char%20s2%5B%5D%29%3B%0A%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s1%5B%5D%20%3D%20%7B'H','e','l','l','o','W','o','r','l','d',%20'%5C0'%7D%3B%0A%20%20%20%20char%20s2%5B%5D%20%3D%20%7B'o','l',%20'%5C0'%7D%3B%0A%0A%20%20%20%20squeeze%28s1,%20s2%29%3B%0A%0A%20%20%20%20printf%28%22%25s%22,%20s1%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D%0A%0Avoid%20squeeze%28char%20s1%5B%5D,%20const%20char%20s2%5B%5D%29%20%7B%0A%20%20%20%20int%20i,%20j,%20k%3B%0A%20%20%20%20k%20%3D%200%3B%0A%0A%20%20%20%20for%20%28i%20%3D%200%3B%20s1%5Bi%5D%20!%3D%20'%5C0'%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20%20%20%20%20for%20%28j%20%3D%200%3B%20%28s1%5Bi%5D%20!%3D%20s2%5Bj%5D%29%20%26%26%20s2%5Bj%5D%20!%3D%20'%5C0'%3B%20%2B%2Bj%29%3B%0A%20%20%20%20%20%20%20%20if%20%28s2%5Bj%5D%20%3D%3D%20'%5C0'%29%0A%20%20%20%20%20%20%20%20%20%20%20%20s1%5Bk%2B%2B%5D%20%3D%20s1%5Bi%5D%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20s1%5Bk%5D%20%3D%20'%5C0'%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>


Try It Out
==========


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex24squeezess?embed=true"></iframe>
