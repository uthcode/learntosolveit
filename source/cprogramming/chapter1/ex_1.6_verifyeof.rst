===========================
1.6 Verify the value of EOF
===========================

Question
--------

Verify the expression `getchar() !=EOF` is 0 or 1.

Solution
--------

.. coderun:: cprogs/ex_1.6_verifyeof.c
   :language: c

Explanation
-----------

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

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20EOF%20is%20-1%2C%20comparison%20with%20%21%3D%20yields%200%20or%201%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20printf%28%22EOF%20value%3A%20%25d%5Cn%22%2C%20EOF%29%3B%0A%20%20%20%20printf%28%22%27a%27%20%21%3D%20EOF%3A%20%25d%5Cn%22%2C%20%27a%27%20%21%3D%20EOF%29%3B%0A%20%20%20%20printf%28%22EOF%20%21%3D%20EOF%3A%20%25d%5Cn%22%2C%20EOF%20%21%3D%20EOF%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
