====================================================
5.16 -d makes comparison on letters, numbers, blanks
====================================================

Question
========

Add the -d (``directory order``) option, which makes comparisons only on
letters, numbers and blanks. Make sure it works in conjunction with -f.

.. coderun:: cprogs/ex_5.16_sort_dfnr.c
   :language: c
   :tab-width: 4


Explanation
===========

This is a command-line sorting program that can sort text lines in different ways based on various options.
The `-d` flag sorts the lines of input in the directory order, that is ignoring punctuation marks.
The `-f` folds the input, that is, it does a case insensitive comparison of lower case and upper case lines.


::

     ./ex_5.16_sort_dfnr -d
    something-anotherthing
    some-thing
    another-thing
    one!
    once
    ^D
    another-thing
    once
    one!
    some-thing
    something-anotherthing


::

    ./ex_5.16_sort_dfnr -df
    Apple
    apple
    apple-pie
    Carrot-Cake


    apple
    Apple
    apple-pie
    Carrot-Cake




Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20sort%20with%20-d%20%28directory%20order%3A%20only%20letters%2Fdigits%29%20option%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cctype.h%3E%0A%23include%20%3Cstring.h%3E%0Aint%20charcmp%28char%20%2As1%2C%20char%20%2As2%2C%20int%20fold%2C%20int%20dir%29%20%7B%0A%20%20%20%20while%20%28%2As1%20%26%26%20%2As2%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28dir%20%26%26%20%21isalnum%28%2As1%29%29%20%7B%20s1%2B%2B%3B%20continue%3B%20%7D%0A%20%20%20%20%20%20%20%20if%20%28dir%20%26%26%20%21isalnum%28%2As2%29%29%20%7B%20s2%2B%2B%3B%20continue%3B%20%7D%0A%20%20%20%20%20%20%20%20int%20c1%20%3D%20fold%20%3F%20tolower%28%2As1%29%20%3A%20%2As1%3B%0A%20%20%20%20%20%20%20%20int%20c2%20%3D%20fold%20%3F%20tolower%28%2As2%29%20%3A%20%2As2%3B%0A%20%20%20%20%20%20%20%20if%20%28c1%20%21%3D%20c2%29%20return%20c1%20-%20c2%3B%0A%20%20%20%20%20%20%20%20s1%2B%2B%3B%20s2%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20%2As1%20-%20%2As2%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20%2Alines%5B3%5D%20%3D%20%7B%22Banana%22%2C%20%22apple%22%2C%20%22Cherry%22%7D%3B%0A%20%20%20%20int%20i%2C%20j%3B%0A%20%20%20%20char%20%2Atmp%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%202%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20for%20%28j%20%3D%20i%2B1%3B%20j%20%3C%203%3B%20j%2B%2B%29%0A%20%20%20%20%20%20%20%20%20%20%20%20if%20%28charcmp%28lines%5Bi%5D%2C%20lines%5Bj%5D%2C%201%2C%200%29%20%3E%200%29%20%7B%20tmp%20%3D%20lines%5Bi%5D%3B%20lines%5Bi%5D%20%3D%20lines%5Bj%5D%3B%20lines%5Bj%5D%20%3D%20tmp%3B%20%7D%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%203%3B%20i%2B%2B%29%20printf%28%22%25s%5Cn%22%2C%20lines%5Bi%5D%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
