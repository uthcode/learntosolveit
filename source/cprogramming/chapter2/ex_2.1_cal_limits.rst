===============================
Exercise 2.1 - Count the Ranges
===============================

Question
========

Write a program to determine the ranges of char, short, int, and long variables,
both signed and unsigned, by printing appropriate values from standard headers
and by direct computation.  Harder if you compute them: determine the ranges of
the various floating-point types.


.. literalinclude:: cprogs/ex_2.1_cal_limits.c
   :language: c

Explanation
===========


The execution of the above program will give::

    Ranges of various floating-point types through calculation:
    Minimum Signed Char -128
    Maximum Signed Char 127
    Minimum Signed Short -32768
    Maximum Signed Short 32767
    Minimum Signed Int -2147483648
    Maximum Signed Int 2147483647
    Minimum Signed Long -9223372036854775808
    Maximum signed Long 9223372036854775807
    Maximum Unsigned Char 255
    Maximum Unsigned Short 65535
    Maximum Unsigned Int 4294967295
    Maximum Unsigned Long 18446744073709551615

    Ranges of various floating-point types from standard headers:
    Minimum Signed Char -128
    Maximum Signed Char 127
    Minimum Signed Short -32768
    Maximum Signed Short 32767
    Minimum Signed Int -2147483648
    Maximum Signed Int 2147483647
    Minimum Signed Long -9223372036854775808
    Maximum signed Long 9223372036854775807
    Maximum Unsigned Char 255
    Maximum Unsigned Short 65535
    Maximum Unsigned Int 4294967295
    Maximum Unsigned Long 18446744073709551615


In order explain how we calculate the maximum values, we will have to do some
bit arthimetic. Let's start by calculating the maximum unsigned char.

Sign bit is usually the left most bit of the type. To make it unsigned, we
remove the sign bit and store 0 in it's place.

To represent (unsigned char) 0 = **0000 0000**
To represent it's complement, (unsigned char) ~0 = **1111 1111**

Right Shift 1 will shift that entire sequence to the right and insert 0 from the
left side, so it will give 0111 1111

Converting 0111 1111 to integer will be::

    0 * 2^7 + 1 * 2^ 6 + 1 * 2^5 + 1 * 2^4 + 1 * 2^3 + 1 *2^2 + 1 * 2^1 + 1 * 2^0
    = 0 * 0 + 1 * 64 + 1 * 32 + 1 * 16 + 1 * 8 + 1 * 4 + 1 * 2 + 1 * 1
    = 0 + 64 + 32 + 16 + 8 + 4 + 2 + 1
    = 127

That is the maximum signed char value. To get the minimum signed char value, we
look for the number in the other end of the number line.

That is got by, multiplying it by -1 and going one number further to the left in
the number line::

    = - 127 -1
    = -128

So our range is displayed like this::

    -128..-2..-1..0 1 2 3 4... 127

Maximum signed short
--------------------

To get the maximum signed short number, we start with unsigned short type again
and repeat the same operations like we did above.

(short)((unsigned short)~0 >> 1)

In our compiler, a short is 2 bytes

(unsigned short) 0 means **0000 0000 0000 0000**
(unsigned short) ~0 means **1111 1111 1111 1111**

Logical right shift, is we are eliminating the sign bit, which is the left most
bit in the sequence.

(unsigned short)~0 >> 1)

Take this portion ``1111 1111 1111 111`` 1  and place it as **1111 1111 1111 111**
And then add 0 to the left **0** 1111 1111 1111 111
Rearranging we get **0111 1111 1111 1111**

What is value of 0111 1111 1111 1111 ?

Similar to above::

    =   0 * 2^15 + 1 * 2^14 + 1 * 2^13 + 1 * 2^12
        + 1 * 2^11 + 1* 2^10 + 1 * 2^9 + 1 * 2^8
        + 1*2^7 + 1 * 2^6 + 1*2^5 + 1*2^4
        + 1* 2^3 + 1*2^2 + 1* 2^1 +1*2^0

        = 16384 + 8192 + 4096 + 2048 + 1024 + 512 + 256 + 128 + 64 + 32 + 16 + 8 + 4 + 2
        = + 1 32767

So, our maximum unsigned short is 32767

Mininum unsigned short will be the negative of that number going one step
further, i.e::

    = -32767 - 1 = -32768

Similarily, we can calculate for int and long types.

For unsigned types, we do not do the shifting (to remove the sign) but simply
print the value of all 1s of the type

(unsigned char)~0;

can be represented as (unsigned char) ~0 = 1111 1111

::

    = 1 * 2^7 + 1 * 2^ 6 + 1 * 2^5 + 1 * 2^4 + 1 * 2^3 + 1 *2^2 + 1 * 2^1 + 1 * 2^0
    = 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1
    = 255
