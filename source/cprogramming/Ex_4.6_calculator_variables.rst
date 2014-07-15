============================================
Exercise 4.6 - RPN Calculator with variables
============================================

Question
========

Add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value.

.. literalinclude:: ../../languages/cprogs/Ex_4.6_calculator_variables.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.6_calculator_variables.c
   :language: c
   :codesite: ideone

Explaination
============

This adds variables to our RPN calculator. An example execution goes like this.

::

    10 A = 20 B = A B +
        30
    v
        30
        

The RPN notation for assigning to variables is like this `10 A =`. When an `=`
sign is encountered the previous value is popped and the value that is stored in
`var` variable (that is the previous one is taken) and then it's value is
assigned to the next popped variable. Thus two variables `A` and `B` are set in
the above expression.

Then `A B +` acts as if we are acting on two numbers. A special variable `v` is
used to assign to the last printed value.

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_4.6_calculator_variables.c`
   * :c-better-explain:`Ex_4.6_calculator_variables.rst`
