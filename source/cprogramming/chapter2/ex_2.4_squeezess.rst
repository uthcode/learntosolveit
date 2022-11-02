============================================================
Exercise 2.4 - Compare S1, S2 To Delete Same Character in S1
============================================================

Question
========

Write an alternative version of squeeze(s1,s2) that deletes each character in s1
that matches any character in the string s2.

.. literalinclude:: ../../languages/cprogs/Ex_2.4_squeezess.c
   :language: c

Explanation
===========

Let's take the two inputs strings as:

    s1: HelloWorld

    s2: ol

Our desired output is::

    HeWrd

This has removed the characters `o` and `l` from the first string. The way
squeeze works is, it take each character from the first string and if there is
no match found, stores it with a new index `k`. If there is a match found in
**s2**, it simply skips it.  The way it skips is realized by the following::

        for(j=0; (s1[i]!=s2[j]) && s2[j]!='\0' ;++j)
            ;
        if(s2[j]=='\0')
            s1[k++] = s1[i];

When the match is found **s1[i] == s2[j]** so our first for loop will **end**.
The second **if condtion** will fail too as s2 is not iterated till the end, so
we do not place the character in **s1[k++]** and we have successfully skipped
it.
