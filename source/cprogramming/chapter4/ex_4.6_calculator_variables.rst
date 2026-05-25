=================================
4.6 RPN Calculator with variables
=================================

Question
========

Add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value.

.. coderun:: cprogs/ex_4.6_calculator_variables.c
   :language: c


Explanation
===========

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

Visualize the Full Solution
---------------------------

* https://pythontutor.com/


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20RPN%20calculator%20with%20named%20variable%20storage%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23define%20MAXVAL%2010%0Aint%20sp%20%3D%200%3B%0Adouble%20val%5BMAXVAL%5D%3B%0Adouble%20variable%5B26%5D%3B%0Avoid%20push%28double%20f%29%20%7B%20if%20%28sp%20%3C%20MAXVAL%29%20val%5Bsp%2B%2B%5D%20%3D%20f%3B%20%7D%0Adouble%20pop%28void%29%20%7B%20return%20sp%20%3E%200%20%3F%20val%5B--sp%5D%20%3A%200.0%3B%20%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20%2F%2A%205%20-%3E%20A%2C%20then%20A%203%20%2B%20%3D%208%20%2A%2F%0A%20%20%20%20push%285%29%3B%0A%20%20%20%20variable%5B%27A%27-%27A%27%5D%20%3D%20pop%28%29%3B%0A%20%20%20%20push%28variable%5B%27A%27-%27A%27%5D%29%3B%0A%20%20%20%20push%283%29%3B%0A%20%20%20%20push%28pop%28%29%20%2B%20pop%28%29%29%3B%0A%20%20%20%20printf%28%22%25.8g%5Cn%22%2C%20pop%28%29%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
