========================
7.8 Print Pages to Files
========================

Question
========

Write a program to print a set of files, starting each new one on a new page,
with a title and a running page count for each file.


.. literalinclude:: cprogs/ex_7.8.c
   :language: c
   :tab-width: 4

Explanation
===========

This takes a file as argument, and prints the file into number of pages, with Page # End as a de-mark at the end of the page.

::

    $ ./ex_7.8 README.md


                            File: README.md

    # https://learntosolveit.com

    [https://learntosolveit.com](https://learntosolveit.com) is a website to learn C programming using K&R book. It uses modern tools, and is designed to be used along with the book.

    To practice the exercises, you can use the online compilers like

    * [https://www.tutorialspoint.com/compile_c_online.php](https://www.tutorialspoint.com/compile_c_online.php)
    * [https://replit.com/](https://replit.com/)
    * [https://www.jdoodle.com/c-online-compiler](https://www.jdoodle.com/c-online-compiler)
    * [https://www.onlinegdb.com/online_c_compiler](https://www.onlinegdb.com/online_c_compiler)

                            Page 1 End.

    * [https://www.codechef.com/ide](https://www.codechef.com/ide)
    * [https://www.programiz.com/c-programming/online-compiler/](https://www.programiz.com/c-programming/online-compiler/).

    I recommend [https://exercism.org](https://exercism.org) as the platform to
    learn programming, including C, and practice with a community of intrinsically
    motivated developers.

    ### Reference Books

    * C Programming Language by Kernighan and Ritchie.

                            Page 2 End.



    [![Netlify Status](https://api.netlify.com/api/v1/badges/27a766e4-762c-420f-92e2-f35441c79f63/deploy-status)](https://app.netlify.com/sites/learntosolveit/deploys)
    [![Documentation Status](https://readthedocs.org/projects/learntosolveit/badge/?version=latest)](http://www.learntosolveit.com/?badge=latest)


    ## Author

    * Senthil Kumaran
    * Email: [senthil@uthcode.com](mailto:senthil@uthcode.com)

                            Page 3 End.

    * Blog: [https://senthil.learntosolveit.com](https://senthil.learntosolveit.com)





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20line%20and%20page%20counters%20control%20file%20pagination%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23define%20LINESPERPAGE%203%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20%2Alines%5B%5D%20%3D%20%7B%22line1%22%2C%22line2%22%2C%22line3%22%2C%22line4%22%2C%22line5%22%7D%3B%0A%20%20%20%20int%20i%2C%20line%20%3D%200%2C%20pg%20%3D%201%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%205%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22%25s%5Cn%22%2C%20lines%5Bi%5D%29%3B%0A%20%20%20%20%20%20%20%20if%20%28%2B%2Bline%20%3D%3D%20LINESPERPAGE%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22---%20Page%20%25d%20end%20---%5Cn%22%2C%20pg%2B%2B%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20line%20%3D%200%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
