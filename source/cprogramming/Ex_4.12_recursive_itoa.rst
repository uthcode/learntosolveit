========================================================================
Exercise 4.12 - convert integer into string by calling recursive routine
========================================================================

Question
========

Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.

.. literalinclude:: ../../languages/cprogs/Ex_4.12_recursive_itoa.c
   :language: c
   :tab-width: 4

   :language: c

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



.. seealso::

   * :c-suggest-improve:`Ex_4.12_recursive_itoa.c`
   * :c-better-explain:`Ex_4.12_recursive_itoa.rst`
