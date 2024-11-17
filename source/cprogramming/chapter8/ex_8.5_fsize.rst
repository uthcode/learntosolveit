==========================
Exercise 8.5 - inode entry
==========================

Question
========

Modify the fsize program to print the other information contained in the inode
entry.


.. literalinclude:: cprogs/ex_8.5_fsize.c
   :language: c
   :tab-width: 4

Explanation
===========

The main purpose of this program information about files and directories, similar to the ls command in Unix-like systems,
but with more detailed information. It prints various file attributes like size, block information, and other metadata.


If a file argument is provided, it gets file statistics using stat to get the file inode and other information.
If the program encounters a directory,  it uses dirwalk to recursively traverse through it and on each file, it does
a stat on the file.

::

    $ ./ex_8.5_fsize source/_templates

        source/_templates
                                     101 source/_templates/index.html Owner: ec2-user
                                     902 source/_templates/layout.html Owner: ec2-user
                                     275 source/_templates/logo.html Owner: ec2-user
                                     60 source/_templates Owner: ec2-user