=======================================================
Exercise 5.11 - entab and detab which accepts arguments
=======================================================

Question
========

Modify the program entab and detab (written as exercises in Chapter 1) to accept
a list of tab stops as arguments. Use the default tab settings if there are no
arguments.

.. literalinclude:: ../../languages/cprogs/Ex_5.11_conddetab.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_5.11_conddetab.c
   :language: c
   :codesite: ideone

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



.. seealso::

   * :c-suggest-improve:`Ex_5.11_conddetab.c`
   * :c-better-explain:`Ex_5.11_conddetab.rst`
