==========================================================
Exercise 2.3 - Converting Hexadecimal Digits Into Integers
==========================================================

Question
========

Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The
allowable digits are 0 through 9, a through f,and A through F.

.. literalinclude:: cprogs/ex_2.3_htoi.c
   :language: c

Explanation
===========

In this program we are going to convert a string of hexadecimal digits into
integer value. If give input as `F` then the output should be 15.  This is done
by the htoi function::

    int htoi(char s[])
    {
    int hexdigit,i,inhex,n;
    i = 0;
    if( s[i] == '0')
    {
        ++i;
        if(s[i] == 'x' || s[i] == 'X')
            ++i;
    }

    n = 0;
    inhex = YES;

    for(;inhex==YES;++i)
    {
        if(s[i] >='0' && s[i] <='9')
            hexdigit= s[i] - '0';
        else if(s[i] >='a' && s[i] <='f')
            hexdigit= s[i] -'a' + 10;
        else if(s[i] >='A' && s[i] <='F')
            hexdigit= s[i] -'A' + 10;
        else
            inhex = NO;

        if(inhex == YES)
            n = 16 * n + hexdigit;
    }
    return n;
    }

In the above fragment of the program we declare some variables such as hexdigit
for storing each digit in hexadecimal ,i as a counter,inhex as flag to see if we
are still looking a hexadecimal and finally n where we store our converted
hexadecimal number.

First we strip off any characters which look like `0x` or `0X` and then we enter
to convert rest of the characters. Then we start the conversion process, we set
the flag index to YES and n to 0.

Then in the for loop as long as index is YES, then we check each character 0 to
9, a to f or A to F. If we find 0 to 9, we store the value char - `0`, if we
find a character between a to f, we store char - `a` + 10, becase hexadecimal
'a' is decimal 10 and similar for character range capital A to F.

Then we take each hex digit and for it's position or previous value stored in n,
we mutiply by 16 and add hexdigit.

.. code-block:: c

        if(inhex == YES)
            n = 16 * n + hexdigit;

For example to convert **0XAF**.

.. raw::

    1. We strip off 0X.
    2. For A, we get the value hexdigit = 10
    3. n = 16 * 0 + 10
         = 10
    4. We gather F, we store hexdigit = 'F' - 'A' + 10;
                                      =  70 - 65  + 10; (70 is ascii value for F, 65 is ascii value for A)
                                      = 15
    5. n = 16 * n + hexdigit
         = 16 * 10 + 15
         = 160 + 15
         = 175

    175

Visualization
=============

.. raw:: html

    <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%0A%0A%23define%20BASE%2016%0A%0Aunsigned%20int%20htoi%28const%20char%20s%5B%5D,%20int%20len%29%3B%0A%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20line%5B%5D%20%3D%20%7B'0','x','d','e','a','d','b','e','e','f'%7D%3B%0A%20%20%20%20int%20len%20%3D%2010%3B%0A%20%20%20%20unsigned%20int%20value%3B%0A%0A%20%20%20%20value%20%3D%20htoi%28line,%20len%29%3B%0A%0A%20%20%20%20printf%28%22The%20value%20of%20%25s%20is%20%25u%20%5Cn%22,%20%28char%20*%29%20line,%20value%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D%0A%0Aunsigned%20int%20htoi%28const%20char%20s%5B%5D,%20int%20len%29%20%7B%0A%20%20%20%20int%20digit%3B%0A%20%20%20%20int%20power%20%3D%201%3B%0A%20%20%20%20unsigned%20int%20result%20%3D%200%3B%0A%20%20%20%20int%20end_index%20%3D%200%3B%0A%0A%20%20%20%20if%20%28s%5B0%5D%20%3D%3D%20'0'%20%26%26%20%28s%5B1%5D%20%3D%3D%20'x'%20%7C%7C%20s%5B1%5D%20%3D%3D%20'X'%29%29%20%7B%0A%20%20%20%20%20%20%20%20end_index%20%3D%202%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20for%28int%20i%3Dlen-1%3B%20i%3E%3Dend_index%3B%20i--%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28s%5Bi%5D%20%3E%3D%20'0'%20%26%26%20s%5Bi%5D%20%3C%3D%20'9'%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20digit%20%3D%20%28s%5Bi%5D%20-%20'0'%29%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20if%20%28s%5Bi%5D%20%3E%3D%20'a'%20%26%26%20s%5Bi%5D%20%3C%3D%20'f'%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20digit%20%3D%20%28s%5Bi%5D%20-%20'a'%29%20%2B%2010%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20if%20%28s%5Bi%5D%20%3E%3D%20'A'%20%26%26%20s%5Bi%5D%20%3C%3D%20'F'%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20digit%20%3D%20%28s%5Bi%5D%20-%20'A'%29%20%2B%2010%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20result%20%2B%3D%20digit%20*%20power%3B%0A%20%20%20%20%20%20%20%20power%20*%3D%20BASE%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%20result%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>

Try It Out
==========


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex23htoi?embed=true"></iframe>
