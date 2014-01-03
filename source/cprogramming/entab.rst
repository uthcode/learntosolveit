=============
Exercise 1-21
=============

Question
--------

Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks
to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would
suffice to reach a tab stop, which should be given preference?


Solution
--------

*entab.c*

.. literalinclude:: ../../languages/cprogs/entab.c
   :language: c
   :tab-width: 2


Explaination
------------

1. We declare TABINC as 8 in `#define TABINC 8` as the number of spaces which make a TAB.
2. We declare two variables **nb** for number of spaces and **nt** for number of tabs.
3. We get the current character by calling getchar() and storing it in variable c and keep track of the position.
4. As soon as a space character is found, we increment the number of spaces or number of tabs. 
   We increment the spaces by pos, if the space is not divisible by TABINC. 
   If the space occurance is divisible by TABINC, we increment the number of tabs. 
   This step collects the minimum number of tabs and blanks.
5. In the else part, when non space is found, we first print the all remaining tabs, then remaining spaces, 
   then print the character. And We reset the position accordingly. 
   If it is a newline, we reset the pos, if it is a tab character, we reset it to previous tab character - 1.
   This step replaces the spaces with minimum tabs and spaces.


