========================================================
Exercise 4.1- strindex which returns rightmost occurance
========================================================

Code
====

Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.

.. literalinclude:: Ex_4.1_strindex_rightmost.c
   :language: c

Explanation
===========

We find the rightmost of index of our substring in this program.  If we ask to
look for pattern "abc" in the line "abcdedfabcde", the program should correctly
identify the rightmost occurance which happens at position 7.

This is done by our `mstringindex` function and in this loop.

::

    result = -1;

    for(i=0;s[i]!='\0';i++)
    {
        for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
            ;
        if(k>0 && t[k] == '\0')
            result = i;
    }

The outer loop goes over each character in string `s` and in the inner we check
if we find a substring `t` matching in the outer loop. If we find a substring
match, we **dont break** the loop, but record the position `i` and proceed
further. Thus our right most match is noted. If no search is found, then the
result, `-1` is returned.


Visualize It
============

.. raw:: html

   <iframe width="100%" height="800" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%0Aint%20mstrindex%28char%20s%5B%5D,%20char%20t%5B%5D%29%3B%0A%0Aint%20main%28int%20argc,%20char%20*argv%5B%5D%29%20%7B%0A%20%20%20%20char%20line%5B%5D%20%3D%20%22abcdedfabcde%22%3B%0A%20%20%20%20char%20pattern%5B%5D%20%3D%20%22abc%22%3B%0A%0A%20%20%20%20int%20found%3B%0A%0A%20%20%20%20found%20%3D%20mstrindex%28line,%20pattern%29%3B%0A%20%20%20%20printf%28%22Found%3A%20%25d%5Cn%22,%20found%29%3B%0A%7D%0A%0Aint%20mstrindex%28char%20s%5B%5D,%20char%20t%5B%5D%29%20%7B%0A%20%20%20%20int%20i,%20j,%20k,%20result%3B%0A%0A%20%20%20%20result%20%3D%20-1%3B%0A%0A%20%20%20%20for%20%28i%20%3D%200%3B%20s%5Bi%5D%20!%3D%20'%5C0'%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20for%20%28j%20%3D%20i,%20k%20%3D%200%3B%20t%5Bk%5D%20!%3D%20'%5C0'%20%26%26%20s%5Bj%5D%20%3D%3D%20t%5Bk%5D%3B%20j%2B%2B,%20k%2B%2B%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%3B%0A%20%20%20%20%20%20%20%20if%20%28k%20%3E%200%20%26%26%20t%5Bk%5D%20%3D%3D%20'%5C0'%29%0A%20%20%20%20%20%20%20%20%20%20%20%20result%20%3D%20i%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20result%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=true&curInstr=0&heapPrimitives=false&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=true"> </iframe>


Try It
======


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/Exercise41?embed=true"></iframe>
