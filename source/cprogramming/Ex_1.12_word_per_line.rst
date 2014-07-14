=================================================
Exercise 1.12 - Print the input one word per line 
=================================================

Question
--------


Write a program that prints its input one word per line.

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.12_word_per_line.c
   :language: c
   :tab-width: 2


.. runcode:: ../../languages/cprogs/Ex_1.12_word_per_line.c
   :language: c
   :codesite: ideone



Explaination
------------

In this program, we read the one character at a time and check if the character
is a space ' ', we print newline character, '\n' thus going to next line in the
output, otherwise we simply print the character c.

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_1.12_word_per_line.c`
   * :c-better-explain:`Ex_1.12_word_per_line.rst`