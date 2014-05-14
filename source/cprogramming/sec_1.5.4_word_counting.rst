===========================
Section 1.5.4 Word Counting
===========================


Program
=======

.. literalinclude:: ../../languages/cprogs/sec_1.5.4_word_counting.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/sec_1.5.4_word_counting.c
   :language: c
   :codesite: ideone
   
Explaination
============

We need to count the number of characters, the number of words and the newlines
in the program. We store the characters in a variable `c`, it's count in nc, the
count of newlines in `nl` and the number of words in `nw`. In order to count the
words, the trick is to know when we enter the word and when we exit the word.
This  is kept track by a `state` variable.

We start with OUTSIDE a word, if we hit a whitespace (' ', \t or \n), we say, we
are outside the word (`state` = OUT). When we read a character again which is
not a whitespace and if were in OUT state earlier, we move to IN state (that is
we saw a new word) and we increment `nw`. For every character we read, we
increment `nc` and for every `\n` we read, we increment `nl`.  The program in
the end prints, the *nl*, *nw* and *nc*.

.. seealso::

   * :c-suggest-improve:`sec_1.5.4_word_counting.c`
   * :c-better-explain:`sec_1.5.4_word_counting.rst`
