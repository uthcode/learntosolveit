===================================
Exercise 7.8 - Print Pages to Files
===================================

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




