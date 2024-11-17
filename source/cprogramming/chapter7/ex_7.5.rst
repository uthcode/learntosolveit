=============================================
Exercise 7.5 - Postfix calculator using scanf
=============================================

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




