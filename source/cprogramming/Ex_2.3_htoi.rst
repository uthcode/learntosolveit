==========================================================
Exercise 2.3 - Converting Hexadecimal Digits Into Integers
==========================================================

Question
========

Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f,and A through F.

.. literalinclude:: ../../languages/cprogs/Ex_2.3_htoi.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_2.3_htoi.c
   :language: c
   :codesite: ideone

Explaination
============

In this program we are going to convert a string of hexadecimal digits into Integer value.
If give input as F then the output should be 15.  This is done by the htoi function::

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





.. seealso::

   * :c-suggest-improve:`Ex_2.3_htoi.c`
   * :c-better-explain:`Ex_2.3_htoi.rst`