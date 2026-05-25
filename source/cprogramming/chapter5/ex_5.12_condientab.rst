=======================================
5.12 entab -m + which accepts arguments
=======================================

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





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20entab%20accumulates%20spaces%3B%20emits%20tab%20when%20tab%20stop%20reached%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20tabstop%5B9%5D%20%3D%20%7B0%2C0%2C0%2C0%2C1%2C0%2C0%2C0%2C1%7D%3B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22%20%20%20%20x%22%3B%20%2F%2A%204%20spaces%20then%20x%20%2A%2F%0A%20%20%20%20int%20i%20%3D%200%2C%20col%20%3D%200%2C%20spaces%20%3D%200%2C%20c%3B%0A%20%20%20%20while%20%28%28c%20%3D%20%28unsigned%20char%29s%5Bi%2B%2B%5D%29%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%20%27%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20spaces%2B%2B%3B%20col%2B%2B%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20if%20%28col%20%3C%3D%208%20%26%26%20tabstop%5Bcol%5D%29%20%7B%20putchar%28%27%5Ct%27%29%3B%20spaces%20%3D%200%3B%20%7D%0A%20%20%20%20%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20while%20%28spaces--%20%3E%200%29%20putchar%28%27%20%27%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20spaces%20%3D%200%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20putchar%28c%29%3B%20col%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20putchar%28%27%5Cn%27%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
