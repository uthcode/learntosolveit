=======================================================================
5.20 dcl handling declarations with function argument types, qualifiers
=======================================================================

Question
========

Expand dcl to handle declarations with function argument types, qualifiers like
const, and so on.

The implementation of this program is from https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_5:Exercise_20

.. coderun:: cprogs/ex_5.20_dcl-funcargs.c
   :language: c
   :tab-width: 4


Explanation
===========

This program is a simple parser that reads a C declaration, breaks down the C declaration into constituent parts and provides
a human readable representation of the declaration. It handles basic declaration syntax including pointers, functions, arrays and parameter declarations.


::

    int simple;
    simple: int
    int dec, *larator, lists[];
    dec: int
    larator: pointer to int
    lists: array[] of int
    static char *storage;
    storage: pointer to static char
    volatile int qualifier;
    qualifier: volatile int
    long unsigned int compound;
    compound: long unsigned int
    void arguments(char *name, double time);
    arguments: function expecting 2 parameters: parameter name (pointer to char) parameter time (double) returning nothing
    int nested_args(char *(*read)(void), void (*write)(char *message));
    nested_args: function expecting 2 parameters: parameter read (pointer to function expecting no parameters returning pointer to char) parameter write (pointer to function expecting 1 parameter: parameter message (pointer to char) returning nothing) returning int
    void unnamed(char (*)(long));
    unnamed: function expecting 1 parameter: unnamed parameter (pointer to function expecting 1 parameter: unnamed parameter (long) returning char) returning nothing
    static const long unsigned int (*book2)[13], *book3[13], complex(volatile char (*(*book6(void))[])(char **book1,void *book4(),void (*book5)()),char (*(*book7[3])())[5]);
    book2: pointer to array[13] of static const long unsigned int
    book3: array[13] of pointer to static const long unsigned int
    complex: function expecting 2 parameters: parameter book6 (function expecting no parameters returning pointer to array[] of pointer to function expecting 3 parameters: parameter book1 (pointer to pointer to char) parameter book4 (obsolescent non-prototype function declaration with unknown parameters returning pointer to void) parameter book5 (pointer to obsolescent non-prototype function declaration with unknown parameters returning nothing) returning volatile char) parameter book7 (array[3] of pointer to obsolescent non-prototype function declaration with unknown parameters returning pointer to array[5] of char) returning static const long unsigned int
    _Thread_local static int multipleStorageClassSpecifiers;
    multipleStorageClassSpecifiers: _Thread_local static int
    const volatile int multipleTypeQualifiers;
    multipleTypeQualifiers: const volatile int
    void everythingSupported(char a, signed char a, unsigned char a, short a, signed short a, short int a, signed short int a, unsigned short a, unsigned short int a, int a, signed a, signed int a, unsigned a, unsigned int a, long a, signed long a, long int a, signed long int a, unsigned long a, unsigned long int a, long long a, signed long long a, long long int a, signed long long int a, unsigned long long a, unsigned long long int a, float a, double a, long double a, _Bool a, float _Complex a, double _Complex a, long double _Complex a, _Atomic int a, const int a, restrict int a, volatile int a, _Thread_local int a, auto int a, extern int a, register int a, static int a);
    everythingSupported: function expecting 42 parameters: parameter a (char) parameter a (signed char) parameter a (unsigned char) parameter a (short) parameter a (signed short) parameter a (short int) parameter a (signed short int) parameter a (unsigned short) parameter a (unsigned short int) parameter a (int) parameter a (signed) parameter a (signed int) parameter a (unsigned) parameter a (unsigned int) parameter a (long) parameter a (signed long) parameter a (long int) parameter a (signed long int) parameter a (unsigned long) parameter a (unsigned long int) parameter a (long long) parameter a (signed long long) parameter a (long long int) parameter a (signed long long int) parameter a (unsigned long long) parameter a (unsigned long long int) parameter a (float) parameter a (double) parameter a (long double) parameter a (_Bool) parameter a (float _Complex) parameter a (double _Complex) parameter a (long double _Complex) parameter a (_Atomic int) parameter a (const int) parameter a (restrict int) parameter a (volatile int) parameter a (_Thread_local int) parameter a (auto int) parameter a (extern int) parameter a (register int) parameter a (static int) returning nothing



Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20tokenize%20a%20C%20declaration%20%E2%80%94%20identify%20%2A%2C%20%5B%5D%2C%20%28%29%2C%20names%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cctype.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20%2As%20%3D%20%22%28%2Afp%29%28int%29%22%3B%0A%20%20%20%20int%20i%20%3D%200%3B%0A%20%20%20%20char%20c%3B%0A%20%20%20%20while%20%28%28c%20%3D%20s%5Bi%2B%2B%5D%29%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20%27%28%27%29%20%20%20%20%20%20%20printf%28%22function%2Fgroup%20%22%29%3B%0A%20%20%20%20%20%20%20%20else%20if%20%28c%20%3D%3D%20%27%2A%27%29%20%20printf%28%22pointer%20%22%29%3B%0A%20%20%20%20%20%20%20%20else%20if%20%28isalpha%28c%29%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22name%20%22%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20while%20%28isalpha%28s%5Bi%5D%29%29%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20if%20%28c%20%3D%3D%20%27%5B%27%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22array%20%22%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20while%20%28s%5Bi%5D%20%26%26%20s%5Bi%5D%20%21%3D%20%27%5D%27%29%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20printf%28%22%5Cn%22%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
