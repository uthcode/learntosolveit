==================================================
Exercise 5.12 - entab -m + which accepts arguments
==================================================

Question
========

Extend entab and detab to accept the shorthand.

.. literalinclude:: cprogs/ex_5.12_condientab.c
   :language: c
   :tab-width: 4


Explanation
===========

This program is similar to the Exercise 5.11, where we send the arguments to
entab and detab. So the main program accepts argc and argv. The program is to
take an argument like -m +n, which means tab stops every n columns;starting at
column m.

The main program sends it to esettab function, both argc, argv and a character
array `tab[MAXLINE-1]`.

esettab function's purpose is to fill the character array `tab` with values YES
(1) or NO(0). It determines from the arguments the -m , which is the POS and +n,
the increment,  and marks at each `m`, the tab value as YES, and then increments
by `n`, and marks the next tab value as YES. If m and n are not provided, it
goes with sane defaults.

The entab function implemented in this program, converts the spaces to tab
characters. So, the entab function, when it encounters a space character c, like
`if(c == ' ')`, it checks the corresponding position in the previously formed
`tab`, if the position value is `YES` or `NO`. If it is YES, then it increments
the tab count, `++nt`, if it is not tab position, it increments the blank count
`++nb`.

When it encounters a first non-space character, then it checks it internal
variables, nt and nb. If `nt` is greater than 0, it meansm that we have tabs to
print, so it prints the tab characters for each nt count. It also prints the
literal tabs, it encounters.

After printing it all the tabs, it checks the variable, `nb`, namely if we have
determined any blanks. If there blanks to be printed, it prints them out too.

And finally, the prints the character using `putchar(c)`.

We also have to handle cases when we encounter a newline character. When we
encounter a newline, like `\n`, we print the new line, but reset the position,
so that our position, `pos`, now becomes 0. When we encounter a tab character,
we increment the position (pos) to the next tab, so that when we encounter the
next space, we can verify it for the new position.



.. seealso::

   * :c-suggest-improve:`Ex_5.12_condientab.c`
   * :c-better-explain:`Ex_5.12_condientab.rst`
