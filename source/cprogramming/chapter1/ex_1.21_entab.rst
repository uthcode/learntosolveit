=====================================
1.21 entab, replaces spaces with tabs
=====================================

Question
--------

Write a program entab that replaces strings of blanks by the minimum number of
tabs and blanks to achieve the same spacing. Use the same tab stops as for
detab. When either a tab or a single blank would suffice to reach a tab stop,
which should be given preference?


Solution
--------

.. coderun:: cprogs/ex_1.21_entab.c
   :language: c

Explanation
===========

1. We declare TABINC as 8 in `#define TABINC 8` as the number of spaces which
make a TAB.

2. We declare two variables **nb** for number of spaces and **nt** for number of
tabs.

3. We get the current character by calling getchar() and storing it in variable
c and keep track of the position.

4. As soon as a space character is found, we increment the number of spaces or
number of tabs. We increment the spaces by pos, if the space is not divisible by
TABINC. If the space occurance is divisible by TABINC, we increment the number
of tabs. This step collects the minimum number of tabs and blanks.

5. In the else part, when non space is found, we first print the all remaining
tabs, then remaining spaces, then print the character. And We reset the position
accordingly. If it is a newline, we reset the pos, if it is a tab character, we
reset it to previous tab character - 1. This step replaces the spaces with
minimum tabs and spaces.

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20replace%20blanks%20with%20tabs%20at%20tab%20stop%20boundaries%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23define%20TABINC%204%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22a%20%20%20b%5Cn%22%3B%0A%20%20%20%20int%20nb%20%3D%200%2C%20nt%20%3D%200%2C%20pos%20%3D%201%2C%20i%20%3D%200%2C%20c%3B%0A%20%20%20%20for%20%28%3B%20%28c%20%3D%20%28int%29%28unsigned%20char%29s%5Bi%2B%2B%5D%29%3B%20%2B%2Bpos%29%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%20%27%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20if%20%28%28pos%20%25%20TABINC%29%20%21%3D%200%29%20%2B%2Bnb%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20else%20%7B%20nb%20%3D%200%3B%20%2B%2Bnt%3B%20%7D%0A%20%20%20%20%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20for%20%28%3B%20nt%20%3E%200%3B%20--nt%29%20putchar%28%27%5Ct%27%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%5Ct%27%29%20nb%20%3D%200%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20else%20for%20%28%3B%20nb%20%3E%200%3B%20--nb%29%20putchar%28%27%20%27%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20putchar%28c%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%5Cn%27%29%20pos%20%3D%200%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
