========================================================================
Exercise 4.12 - convert integer into string by calling recursive routine
========================================================================

Question
========

Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.

.. literalinclude:: cprogs/ex_4.12_recursive_itoa.c
   :language: c
   :tab-width: 4

Explanation
===========

The main part of this program is the `itoa` routine, which takes an `integer n`
and `string s` and is called recursively.

::

    void itoa(int n,char s[])
    {
        static int i;

        if(n/10)
            itoa(n/10,s);
        else
        {
            i = 0;
            if( n < 0)
                s[i++]='-';
        }

        s[i++] = abs(n) % 10 + '0';

        s[i] = '\0';

    }


In the first invocation from the main program, this is called with `n = 1723`
and within the program the number n is divided by 10 (until it is less than 10),
and the new number (which is old number / 10) is called with `itoa` again. When
we reach the first digit of the number, the number is converted to a string
using `abs(n) % 10 + '0'` and stored in the s array. The array is closed with
`\0`, in subsequent recurssion, the next values like 7,2,3 will override \0
stored from the previous iteration and in the last call of the recursion, the
number the complete number is transformed from integer to string. `s` will look
like `['1','7','2','8','\0']`  and this will be printed in the main program.

Visualize It
============

.. raw:: html

    <iframe width="100%" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%23include%20%3Cmath.h%3E%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0Avoid%20itoa%28int%20n,%20char%20s%5B%5D%29%3B%0A%0Aint%20main%28int%20argc,%20char%20*argv%5B%5D%29%20%7B%0A%20%20%20%20int%20n%20%3D%20123456789%3B%0A%20%20%20%20char%20s%5B100%5D%3B%0A%20%20%20%20itoa%28n,%20s%29%3B%0A%20%20%20%20printf%28%22%25s%5Cn%22,%20s%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A%0Avoid%20itoa%28int%20n,%20char%20s%5B%5D%29%20%7B%0A%20%20%20%20static%20int%20i%20%3D%200%3B%0A%20%20%20%20if%20%28n%20/%2010%29%20%7B%0A%20%20%20%20%20%20%20%20itoa%28n%20/%2010,%20s%29%3B%0A%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20if%20%28n%20%3C%200%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20s%5Bi%2B%2B%5D%20%3D%20'-'%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20s%5Bi%2B%2B%5D%20%3D%20abs%28n%29%20%25%2010%20%2B%20'0'%3B%0A%20%20%20%20s%5Bi%5D%20%3D%20'%5C0'%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=true&curInstr=0&heapPrimitives=false&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=true"> </iframe>

Try It
======


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex412recursiveitoa?embed=true"></iframe>
