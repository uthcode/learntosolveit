======================================
Exercise 1.6 - Verify the value of EOF
======================================

Question
--------

Verify the expression `getchar() !=EOF` is 0 or 1.

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.6_verifyeof.c
   :language: c
   :tab-width: 2

.. runcode:: ../../languages/cprogs/Ex_1.6_verifyeof.c
   :language: c
   :codesite: ideone

Explanation
===========

1. This program is similar to the previous one Ex 1.5, wherein after it gets the
input, it prints the value of the expression getchar() != EOF.

2. For a file with this contents

::

    $cat afile
    contents


3. We compile and run the program.

::

    $gcc Ex1.6_verifyeof.c -o eof
    $ ./eof < afile
    1 c1 o1 n1 t1 e1 n1 t1 s1

    0

4. We see that when char is not EOF, it is printing 1 and when it is EOF, 0 is
printed.



.. seealso::

   * :c-suggest-improve:`Ex_1.6_verifyeof.c`
   * :c-better-explain:`Ex_1.6_verifyeof.rst`
   




