============================
Section 8.2 - Read and Write
============================

Question
========

Copy input to output by using read and write system calls.


.. literalinclude:: cprogs/sec_8_2_read_write.c
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