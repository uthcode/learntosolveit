==================================================================
5.4 strend returns 1 if string t occurs at the end of the string s
==================================================================

Question
========

Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.

.. literalinclude:: cprogs/ex_5.4_strend.c
   :language: c
   :tab-width: 4

Explanation
===========

This program determines if the string `t` occurs at the end of string `s`. So
the output of the program will look like.

::

   $ ./a.out
   something
   thing
   1

   $ ./a.out
   something
   non
   0
   

The primary part of this program is the `strend` function, which takes two
character pointers, `s` and `t`. It calculates the length of t and stores in the
variable len. And then, we back off till the last characters in both s and t.

::

    while(*s!='\0')
        ++s;
    --s;

    while(*t!='\0')
        ++t;

    --t;


And then we look for the match from the end. This is checked in this while loop.
While the len is > 0, check if s and t are same and back off one character at a
time.

::


    while(len > 0)
    {
        if(*t==*s)
        {
            --t;
            --s;
            --len;
        }
        else
            return 0;
    }
    if( len == 0)
        return 1;
        

If the string t exhausts, that is, it's length, len becomes 0, then we known
that string `t` occurs at the end of  string `s` and we return 1. Otherwise, we
return 0.





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20walk%20both%20pointers%20to%20ends%2C%20then%20compare%20backwards%20for%20suffix%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20strend%28char%20%2As%2C%20char%20%2At%29%20%7B%0A%20%20%20%20char%20%2Aps%20%3D%20s%2C%20%2Apt%20%3D%20t%3B%0A%20%20%20%20while%20%28%2Aps%29%20ps%2B%2B%3B%0A%20%20%20%20while%20%28%2Apt%29%20pt%2B%2B%3B%0A%20%20%20%20while%20%28pt%20%3E%20t%20%26%26%20ps%20%3E%20s%20%26%26%20%2A--pt%20%3D%3D%20%2A--ps%29%3B%0A%20%20%20%20return%20%2Apt%20%3D%3D%20%2Aps%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20strend%28%22hello%22%2C%20%22lo%22%29%29%3B%20%2F%2A%201%20%2A%2F%0A%20%20%20%20printf%28%22%25d%5Cn%22%2C%20strend%28%22hello%22%2C%20%22hi%22%29%29%3B%20%2F%2A%200%20%2A%2F%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
