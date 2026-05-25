=======================================
5.1 get next integer from input to \*pn
=======================================

Question
========

As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.

.. coderun:: cprogs/ex_5.1_getint.c
   :language: c
   :tab-width: 4


Explanation
===========

We are to explain the function ``getint(int *)`` which takes a pointer to an
integer as the argument. We also use ``getch`` and ``ungetch`` as two functions,
from chapter 4, which work on ``buf`` of ``BUFSIZE`` sharing a global variable
called ``bufp``. ``ungetch`` function returns the character read to ``buf`` while
``getch`` tries to read that character to our program and if no character is
present, it uses ``getchar`` to get the character.

In this program, we declare an ``array`` of size of 1000, and we send each digit
of the array to getint using a call like ``getint(&array[n])``. Our intention is
to load the characters in array with a valid integer format like ``+/-1234EOF``,
that is + or - 1234 and ending with EOF character.

In getint function, we get a character and if it's space, we simply ignore it.
And this snippet.

::

    if(!isdigit(c) && c !=EOF && c!='+' && c!='-')
    {
        ungetch(c); /* it's not a number */
        return 0;
    }

Ensures that if we get a character which is not +,-, digit, EOF, then we return
0 and in the main loop we end the program.  That is, we strictly look for
characters that can be converted to integer in this program. So the only valid
inputs are like this.

::

    123
    +123
    -123

And if we get any invalid input.

::

    abc
    %**

Then the program will immediately end.


So, on a valid input, the initial check is done to see if there is a ``sign`` and
if yes, it stores the ``sign`` and then it goes about finding the next digit in a
for loop and calculates the number using this expression.

::
    
    *pn = 10 * *pn + (c-'0')
    
This is responsible for converting the character like ``1`` to integer 1 and store
it in ``*pn``, the place in the array. We multiply the number by sign and when we
find EOF, we store that EOF, so that the program terminates correctly.

Once the getint sees an EOF, we end the program and print the contents of the
array.





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20getint%20reads%20an%20integer%20via%20a%20pointer%20argument%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20getint%28int%20%2Apn%29%20%7B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%2242%22%3B%0A%20%20%20%20int%20i%20%3D%200%3B%0A%20%20%20%20%2Apn%20%3D%200%3B%0A%20%20%20%20while%20%28s%5Bi%5D%20%3E%3D%20%270%27%20%26%26%20s%5Bi%5D%20%3C%3D%20%279%27%29%20%7B%20%2Apn%20%3D%20%2Apn%20%2A%2010%20%2B%20%28s%5Bi%5D%20-%20%270%27%29%3B%20i%2B%2B%3B%20%7D%0A%20%20%20%20return%20i%20%3E%200%20%3F%201%20%3A%200%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20n%3B%0A%20%20%20%20if%20%28getint%28%26n%29%20%3E%200%29%20printf%28%22%25d%5Cn%22%2C%20n%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
