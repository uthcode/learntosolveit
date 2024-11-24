=================================
Section 8.3 open and create calls
=================================

Question
========

Demonstrate the ``cp`` like program which copies the contents of one file to another.


.. literalinclude:: cprogs/sec_8.3_open_creat.c
   :language: c


Explanation
===========

::

    while ((n = read(f1, buf, BUFSIZE)) > 0)
        if (write(f2, buf, n) != n)

Reads up to BUFSIZE bytes from source file into buffer. Writes the same number of bytes to destination file. continues
until entire file is copied
