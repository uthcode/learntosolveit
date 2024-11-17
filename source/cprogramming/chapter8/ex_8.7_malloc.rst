=======================================
Exercise 8.7 - Error checking by malloc
=======================================

Question
========

Malloc accepts a size request without checking its plausibility; free believes
that the block it is asked to free contains a valid size field. Improve these
routines so they make more pains with error checking.

.. literalinclude:: cprogs/ex_8.7_malloc.c
   :language: c

Explanation
===========

This is an error checking implementation of malloc. If it cannot allocate more bytes, it will throw an error

::

    if (nbytes > MAXBYTES) {
        fprintf(stderr, "alloc: can't allocate more than %u bytes\n", MAXBYTES);
        return NULL;
    }

