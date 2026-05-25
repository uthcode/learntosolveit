=====================================
1.20 detab, replaces tabs with spaces
=====================================

Question
--------


Write a program detab that replaces tabs in the input with the proper number of
blanks to space to the next tab stop. Assume a fixed set of tab stops, say every
n columns. Should n be a variable or a symbolic parameter?

Solution
--------

.. coderun:: cprogs/ex_1.20_detab.c
   :language: c

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

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20replace%20tab%20with%20spaces%20to%20align%20to%20tab%20stops%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23define%20TABINC%204%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22a%5Ctb%5Cn%22%3B%0A%20%20%20%20int%20nb%2C%20pos%20%3D%201%2C%20i%20%3D%200%2C%20c%3B%0A%20%20%20%20while%20%28%28c%20%3D%20%28int%29%28unsigned%20char%29s%5Bi%2B%2B%5D%29%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%5Ct%27%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20nb%20%3D%20TABINC%20-%20%28%28pos-1%29%20%25%20TABINC%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20while%20%28nb%20%3E%200%29%20%7B%20putchar%28%27%23%27%29%3B%20%2B%2Bpos%3B%20--nb%3B%20%7D%0A%20%20%20%20%20%20%20%20%7D%20else%20if%20%28c%20%3D%3D%20%27%5Cn%27%29%20%7B%20putchar%28c%29%3B%20pos%20%3D%201%3B%20%7D%0A%20%20%20%20%20%20%20%20else%20%7B%20putchar%28c%29%3B%20%2B%2Bpos%3B%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
