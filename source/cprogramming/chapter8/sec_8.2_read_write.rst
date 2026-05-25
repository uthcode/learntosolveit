==================
8.2 Read and Write
==================

Question
========

Copy input to output by using read and write system calls.


.. coderun:: cprogs/sec_8_2_read_write.c
   :language: c
   :tab-width: 4

Explanation
===========

This uses the read and write system calls to copy input to output.

::

    # Compile the program

    gcc copy.c -o copy

    # Test 1: Echo a simple string

    echo "Hello, World!" | ./copy

    # Test 2: Multiple lines

    cat << 'EOL' | ./copy
    Line 1
    Line 2
    Line 3
    EOL

    # Test 3: Binary data (create a file with some null bytes)

    dd if=/dev/zero bs=1024 count=1 2>/dev/null | ./copy > /dev/null
Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20read%20into%20buffer%20and%20write%20from%20buffer%20%E2%80%94%20the%20copy%20loop%20pattern%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20src%5B%5D%20%3D%20%22hi%5Cn%22%3B%0A%20%20%20%20char%20buf%5B4%5D%3B%0A%20%20%20%20int%20n%20%3D%203%2C%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20n%3B%20i%2B%2B%29%20buf%5Bi%5D%20%3D%20src%5Bi%5D%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20n%3B%20i%2B%2B%29%20putchar%28buf%5Bi%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
