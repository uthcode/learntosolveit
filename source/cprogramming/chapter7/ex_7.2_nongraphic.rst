===================================================================
Exercise 7.2 - print non-graphic characters in octal or hexadecimal
===================================================================

Question
========

Write a program that will print arbitrary input in a sensible way. As a minimum,
it should print non-graphic characters in octal or hexadecimal according to
local custom, and break long text lines.

.. literalinclude:: cprogs/ex_7.2_nongraphic.c
   :language: c
   :tab-width: 4

Explanation
===========

We use the standard library function `iscntrl` declared in `ctype.h` to determine if a character is a control character.
We keep track of the position to print the output in the `inc` function and print the output in the `putchar` function.
If there is special character, we allocate 6 characters to it and print the character in octal along with the special
character.


Visualize
=========

.. raw:: html

    <iframe width="100%" height="800" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=/**%0A%20*%20Write%20a%20program%20that%20will%20print%20arbitrary%20input%20in%20a%20sensible%20way.%20As%20a%0A%20*%20minimum,%20it%20should%20print%20non-graphic%20characters%20in%20octal%20or%20hexadecimal%0A%20*%20according%20to%20local%20custom,%20and%20break%20long%20text%20lines.%0A%20*/%0A%0A%23include%20%3Cctype.h%3E%0A%23include%20%3Cstdio.h%3E%0A%0A%23define%20MAXLINE%20100%20/*%20maximum%20number%20of%20chars%20in%20one%20line%20*/%0A%23define%20OCTLEN%206%20%20%20%20/*%20length%20of%20an%20octal%20value%20*/%0A%0Aconst%20char%20*input%20%3D%20%22This%5Ctis%5Cta%5Cttest.%20%20%20With%20a%20%20%20very%20%20%20long%20line.%22%3B%0Aint%20input_index%20%3D%200%3B%0A%0Aint%20_getchar%28void%29%20%7B%0A%20%20%20%20if%20%28input%5Binput_index%5D%20%3D%3D%20'%5C0'%29%20%7B%0A%20%20%20%20%20%20%20%20return%20EOF%3B%0A%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20return%20input%5Binput_index%2B%2B%5D%3B%0A%20%20%20%20%7D%0A%7D%0A%0A%0A/*%20inc%20%3A%20increment%20position%20counter%20for%20output%20*/%0Aint%20inc%28int%20pos,%20int%20n%29%20%7B%0A%20%20%20%20if%20%28pos%20%2B%20n%20%3C%20MAXLINE%29%0A%20%20%20%20%20%20%20%20return%20pos%20%2B%20n%3B%0A%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20putchar%28'%5Cn'%29%3B%0A%20%20%20%20%20%20%20%20return%20n%3B%0A%20%20%20%20%7D%0A%7D%0A%0A/*%20print%20arbitrary%20input%20in%20a%20sensible%20way%20*/%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20c,%20pos%3B%0A%0A%20%20%20%20pos%20%3D%200%3B%20/*%20position%20in%20the%20line%20*/%0A%0A%20%20%20%20while%20%28%28c%20%3D%20_getchar%28%29%29%20!%3D%20EOF%29%0A%20%20%20%20%20%20%20%20if%20%28iscntrl%28c%29%20%7C%7C%20c%20%3D%3D%20'%20'%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20/*%20non-graphic%20or%20blank%20character%20*/%0A%20%20%20%20%20%20%20%20%20%20%20%20pos%20%3D%20inc%28pos,%20OCTLEN%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20printf%28%22%5C%5C%2503o%22,%20c%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20/*%20newline%20character%20*/%0A%20%20%20%20%20%20%20%20%20%20%20%20if%20%28c%20%3D%3D%20'%5Cn'%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20pos%20%3D%200%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20putchar%28'%5Cn'%29%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20/*%20graphic%20character%20*/%0A%20%20%20%20%20%20%20%20%20%20%20%20pos%20%3D%20inc%28pos,%201%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20putchar%28c%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D&codeDivHeight=400&codeDivWidth=350&cumulative=false&curInstr=0&heapPrimitives=nevernest&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false"> </iframe>
