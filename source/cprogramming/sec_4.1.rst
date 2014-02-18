=======================================================
Section 4.1 - Find the pattern in the line and print it
=======================================================

Program
=======


.. literalinclude:: ../../languages/cprogs/sec_4.1.c
   :language: c
   :tab-width: 4
   

.. runcode:: ../../languages/cprogs/sec_4.1.c
   :language: c
   :codesite: ideone


Explaination
============

This program searches particular pattern in a given string.  As per the program we are going to search for the pattern ould and print the line which has the same.  
Let us say that we give the input as::

	This line would print
	This line will not print

The output would be::

	This line would print

It contains the pattern ould.  
This is achieved by


.. seealso::

   * :c-suggest-improve:`sec_4.1.c`
   * :c-better-explain:`sec_4.1.rst`
