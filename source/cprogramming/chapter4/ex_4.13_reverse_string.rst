====================================
Exercise 4.13 - reverse the string s
====================================

Question
========

Write a recursive version of the function reverse(s), which reverses the string
s in place.

.. literalinclude:: cprogs/Ex_4.13_reverse_string.c
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

