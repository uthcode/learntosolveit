=============================================================================
Exercise 5.4 - strend returns 1 if string t occurs at the end of the string s
=============================================================================

Question
========

Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.

.. literalinclude:: ../../languages/cprogs/Ex_5.4_strend.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_5.4_strend.c
   :language: c
   :codesite: ideone

Explaination
============

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

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_5.4_strend.c`
   * :c-better-explain:`Ex_5.4_strend.rst`
