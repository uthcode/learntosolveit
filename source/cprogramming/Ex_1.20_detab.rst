================================================
Exercise 1.20 - detab, replaces tabs with spaces
================================================

Question
--------


Write a program detab that replaces tabs in the input with the proper number of
blanks to space to the next tab stop. Assume a fixed set of tab stops, say every
n columns. Should n be a variable or a symbolic parameter?

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.20_detab.c
   :language: c
   :tab-width: 2

.. runcode:: ../../languages/cprogs/Ex_1.20_detab.c
   :language: c
   :codesite: ideone


Explanation
===========

We declare TABINC as 8 in #define TABINC 8 as the number of spaces which make a
TAB.

We start counting the pos from 1 for every new line and we increment pos for all
the characters and print the character, which are not tabs.  This is
demonstrated by the else statements in our program.

When we hit a tab \t character, then we need to determine how many spaces we
need to replace the \t with.

For e.g.::

	hello   | I press a tab and reach |
	hello###| It should be substibuted with 3 #, 
		  	 
The way 3 # is calculated by `TABINC - length of ('hello')`
that is 8 - 5 = 3.

This explains well, if hello is the starting word. The way to determine the tabs
to spaces later in the line is by keeping track of the number of characters in
the line (that is variable pos in our program.)

For e.g

::

	hello   world   is      great
	hello###world###is######great


To determine the number of tabs to spaces between **is** and **great**

We track the pos till **s**, we encounter the tab position at be 19.

::

	nb = TABINC - (( pos - 1) % TABINC);
	nb = TABINC - ((19 - 1))  % TABINC);
	nb = TABINC - (18 % TABINC);
	nb = TABINC - (18 % 8);
	nb = TABINC - 2;
	nb = 8 - 2;
	nb = 6

Once we determine the nb, we simply print # character to denote a visible space
and increment the position each character.



.. seealso::

   * :c-suggest-improve:`Ex_1.20_detab.c`
   * :c-better-explain:`Ex_1.20_detab.rst`

