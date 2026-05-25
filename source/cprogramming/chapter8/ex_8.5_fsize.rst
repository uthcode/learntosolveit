===============
8.5 inode entry
===============

Question
========

Modify the fsize program to print the other information contained in the inode
entry.


.. coderun:: cprogs/ex_8.5_fsize.c
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

Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20recursive%20directory%20walk%20%E2%80%94%20visit%20each%20file%20entry%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Astruct%20entry%20%7B%20char%20%2Aname%3B%20int%20is_dir%3B%20long%20size%3B%20%7D%3B%0Avoid%20dirwalk%28struct%20entry%20entries%5B%5D%2C%20int%20n%29%20%7B%0A%20%20%20%20int%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20n%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28entries%5Bi%5D.is_dir%29%20printf%28%22%5B%25s%2F%5D%5Cn%22%2C%20entries%5Bi%5D.name%29%3B%0A%20%20%20%20%20%20%20%20else%20printf%28%22%25s%20%28%25ld%20bytes%29%5Cn%22%2C%20entries%5Bi%5D.name%2C%20entries%5Bi%5D.size%29%3B%0A%20%20%20%20%7D%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20struct%20entry%20entries%5B%5D%20%3D%20%7B%0A%20%20%20%20%20%20%20%20%7B%22file1.c%22%2C%200%2C%201024%7D%2C%0A%20%20%20%20%20%20%20%20%7B%22subdir%22%2C%20%201%2C%200%7D%2C%0A%20%20%20%20%20%20%20%20%7B%22main.c%22%2C%20%200%2C%20512%7D%2C%0A%20%20%20%20%7D%3B%0A%20%20%20%20dirwalk%28entries%2C%203%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
