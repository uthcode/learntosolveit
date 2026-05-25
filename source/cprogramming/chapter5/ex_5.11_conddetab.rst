============================================
5.11 entab and detab which accepts arguments
============================================

Question
========

Modify the program entab and detab (written as exercises in Chapter 1) to accept
a list of tab stops as arguments. Use the default tab settings if there are no
arguments.

.. literalinclude:: cprogs/ex_5.11_conddetab.c
   :language: c
   :tab-width: 4

Explanation
===========

This program is about accepting the arguments for entab and entab as command
line args. So the main program accepts argc and argv.

The program is to take an argument like -m +n, which means tab stops every n
columns;starting at column m.

So, the main program sends it to esettab function, both argc, argv and a
character array tab[MAXLINE-1];

If we had not given, m or n, it takes the TABINC of 8 and starts with the first
colummn and marking every TABINC position as tab (setting the value to YES) in
character array tab. If we give the values for m and n, it marks the
corresponding position in tab as 'yes'.

This function only implements detab, which replaces the tab with spaces. So,
when a sentence is read with detab, the function consults `tabpos` function to
see if it s tab. If it is tab, then till it meets the next tab, it will output
space ' ', thus converting the tabs to spaces.


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20tab%20stop%20array%20%E2%80%94%20tabstop%5Bcol%5D%3D1%20marks%20where%20tabs%20expand%20to%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20tabstop%5B9%5D%20%3D%20%7B0%2C0%2C0%2C0%2C1%2C0%2C0%2C0%2C1%7D%3B%20%2F%2A%20stops%20at%20col%204%20and%208%20%2A%2F%0A%20%20%20%20int%20col%3B%0A%20%20%20%20for%20%28col%20%3D%200%3B%20col%20%3C%3D%208%3B%20col%2B%2B%29%0A%20%20%20%20%20%20%20%20printf%28%22col%20%25d%3A%20tabstop%3D%25d%5Cn%22%2C%20col%2C%20tabstop%5Bcol%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
