==========================================================
Exercise 2.3 - Converting Hexadecimal Digits Into Integers
==========================================================

Question
========

Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The
allowable digits are 0 through 9, a through f,and A through F.

.. literalinclude:: ../../languages/cprogs/Ex_2.3_htoi.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_2.3_htoi.c
   :language: c
   :codesite: ideone

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

        if(inhex == YES)
            n = 16 * n + hexdigit;
            
For example to convert **0XAF**.

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

**175**

.. git_changelog::       

.. seealso::

   * :c-suggest-improve:`Ex_2.3_htoi.c`
   * :c-better-explain:`Ex_2.3_htoi.rst`
