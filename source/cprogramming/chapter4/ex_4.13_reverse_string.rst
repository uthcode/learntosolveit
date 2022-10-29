====================================
Exercise 4.13 - reverse the string s
====================================

Question
========

Write a recursive version of the function reverse(s), which reverses the string
s in place.

.. literalinclude:: cprogs/ex_4.13_reverse_string.c
   :language: c


Explanation
===========

The main part of this program is the reverser function.

::

    void reverser(char s[],int i,int len)
    {
        int c,j;

        j = len - (i + 1);

        if( i < j )
        {
            c = s[i];
            s[i] = s[j];
            s[j] = c;

            reverser(s,++i,len);
        }
    }


The string to be reversed is taken in the character array `s` and the first
invocation is called with `i=0`. The value `len` stands for the length of the
string. During each invocation, `j` is calculated as `len - (i+1)`, which is the
character from the end which needs to be swapped and  characters at `i is
swapped with j`. And then reverser is called again with the next value of i,
i.e, `++i`. This whole operation is done till i (from left hand side of the
string)  is less than j (from the right end), i.e, `i < j`.

Visualize It
============

.. raw:: html

   <iframe width="100%" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0A%0A%23define%20MAXLINE%201000%0A%0Avoid%20reverse%28char%20s%5B%5D,%20int%20i,%20int%20j%29%3B%0A%0Aint%20main%28void%29%0A%7B%0A%20%20%20%20char%20s%5BMAXLINE%5D%3B%0A%20%20%20%20int%20i,%20j%3B%0A%0A%20%20%20%20printf%28%22Enter%20a%20string%3A%20%22%29%3B%0A%20%20%20%20fgets%28s,%20MAXLINE,%20stdin%29%3B%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20j%20%3D%20strlen%28s%29%20-%201%3B%0A%20%20%20%20reverse%28s,%20i,%20j%29%3B%0A%20%20%20%20printf%28%22Reversed%20string%3A%20%25s%5Cn%22,%20s%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A%0Avoid%20reverse%28char%20s%5B%5D,%20int%20i,%20int%20j%29%0A%7B%0A%20%20%20%20int%20c%3B%0A%0A%20%20%20%20if%20%28i%20%3C%20j%29%20%7B%0A%20%20%20%20%20%20%20%20c%20%3D%20s%5Bi%5D%3B%0A%20%20%20%20%20%20%20%20s%5Bi%5D%20%3D%20s%5Bj%5D%3B%0A%20%20%20%20%20%20%20%20s%5Bj%5D%20%3D%20c%3B%0A%20%20%20%20%20%20%20%20reverse%28s,%20%2B%2Bi,%20--j%29%3B%0A%20%20%20%20%7D%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=true&curInstr=0&heapPrimitives=false&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=true"> </iframe>

Try It
======


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex413reversestring?embed=true"></iframe>
