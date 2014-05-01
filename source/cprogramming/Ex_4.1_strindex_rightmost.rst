========================================================
Exercise 4.1- strindex which returns rightmost occurance
========================================================

Question
========

Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.

.. literalinclude:: ../../languages/cprogs/Ex_4.1_strindex_rightmost.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.1_strindex_rightmost.c
   :language: c
   :codesite: ideone

Explaination
============

We find the rightmost of index of our substring in this program.  If we ask to
look for pattern "abc" in the line "abcdedfabcde", the program should correctly
identify the rightmost occurance which happens at position 7.

This is done by our `mstringindex` function and in this loop.

::

    result = -1;

    for(i=0;s[i]!='\0';i++)
    {
        for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
            ;
        if(k>0 && t[k] == '\0')
            result = i;
    }

The outer loop goes over each character in string `s` and in the inner we check
if we find a substring `t` matching in the outer loop. If we find a substring
match, we **dont break** the loop, but record the position `i` and proceed
further. Thus our right most match is noted. If no search is found, then the
result, `-1` is returned.


.. seealso::

   * :c-suggest-improve:`Ex_4.1_strindex_rightmost.c`
   * :c-better-explain:`Ex_4.1_strindex_rightmost.rst`
