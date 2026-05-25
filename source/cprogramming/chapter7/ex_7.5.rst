==================================
7.5 Postfix calculator using scanf
==================================

Question
========

Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do the
input and number conversion.

.. literalinclude:: cprogs/ex_7.5.c
   :language: c
   :tab-width: 4

Explanation
===========

In this Reverse Polish Notation Calculator, we use scanf in the getch function. Instead of getchar this uses the function
scanf from the input output library introduced in this chapter.


::

    #define BUFSIZE 100
    char buf[BUFSIZE];
    int bufp = 0;

    int getch(void) {
        char c;
        if (bufp > 0) {
            return buf[--bufp];
        } else {
            scanf("%c", &c);
            return c;
        }
    }





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20RPN%20stack%20%E2%80%94%20push%2C%20pop%2C%20and%20apply%20arithmetic%20operator%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20sp%20%3D%200%3B%0Adouble%20val%5B4%5D%3B%0Avoid%20push%28double%20v%29%20%7B%20if%20%28sp%20%3C%204%29%20val%5Bsp%2B%2B%5D%20%3D%20v%3B%20%7D%0Adouble%20pop%28void%29%20%20%20%20%7B%20return%20sp%20%3E%200%20%3F%20val%5B--sp%5D%20%3A%200.0%3B%20%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20double%20op2%3B%0A%20%20%20%20push%285.0%29%3B%20push%283.0%29%3B%0A%20%20%20%20op2%20%3D%20pop%28%29%3B%20push%28pop%28%29%20-%20op2%29%3B%0A%20%20%20%20printf%28%225%203%20-%20%3D%20%25.0f%5Cn%22%2C%20pop%28%29%29%3B%0A%20%20%20%20push%282.0%29%3B%20push%284.0%29%3B%0A%20%20%20%20push%28pop%28%29%20%2B%20pop%28%29%29%3B%0A%20%20%20%20printf%28%222%204%20%2B%20%3D%20%25.0f%5Cn%22%2C%20pop%28%29%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
