====================
6.6 define processor
====================

Question
========

Implement a simple version of the #define processor (i.e., no arguments)
suitable for use with C programs, based on the routines of this section. You may
also find getch and ungetch helpful.

.. literalinclude:: cprogs/ex_6.6.c
   :language: c
   :tab-width: 4

Explanation
===========

This implements a simple version of `#define` pre-processor used in C programs.
In the program program it identifies `#define key value` in the given text, and then using the previously taught
concepts of install, lookup and undef to create a hash table, to keep track of the identified key value pairs in
a hash table.

Example output.

::

	#define key value x
	key->value





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20hash%20table%20install%2Flookup%20for%20%23define%20name-%3Edefn%20mapping%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%23define%20HASHSIZE%207%0Astruct%20nlist%20%7B%20char%20name%5B8%5D%3B%20char%20defn%5B8%5D%3B%20struct%20nlist%20%2Anext%3B%20%7D%3B%0Astatic%20struct%20nlist%20%2Atab%5BHASHSIZE%5D%3B%0Aunsigned%20hash%28char%20%2As%29%20%7B%0A%20%20%20%20unsigned%20h%20%3D%200%3B%0A%20%20%20%20while%20%28%2As%29%20h%20%3D%20%28unsigned%29%2As%2B%2B%20%2B%2031%20%2A%20h%3B%0A%20%20%20%20return%20h%20%25%20HASHSIZE%3B%0A%7D%0Avoid%20install%28char%20%2Aname%2C%20char%20%2Adefn%29%20%7B%0A%20%20%20%20unsigned%20h%20%3D%20hash%28name%29%3B%0A%20%20%20%20struct%20nlist%20%2Anp%20%3D%20malloc%28sizeof%20%2Anp%29%3B%0A%20%20%20%20strncpy%28np-%3Ename%2C%20name%2C%207%29%3B%20np-%3Ename%5B7%5D%20%3D%200%3B%0A%20%20%20%20strncpy%28np-%3Edefn%2C%20defn%2C%207%29%3B%20np-%3Edefn%5B7%5D%20%3D%200%3B%0A%20%20%20%20np-%3Enext%20%3D%20tab%5Bh%5D%3B%20tab%5Bh%5D%20%3D%20np%3B%0A%7D%0Achar%20%2Alookup%28char%20%2Aname%29%20%7B%0A%20%20%20%20struct%20nlist%20%2Anp%3B%0A%20%20%20%20for%20%28np%20%3D%20tab%5Bhash%28name%29%5D%3B%20np%3B%20np%20%3D%20np-%3Enext%29%0A%20%20%20%20%20%20%20%20if%20%28%21strcmp%28name%2C%20np-%3Ename%29%29%20return%20np-%3Edefn%3B%0A%20%20%20%20return%20NULL%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20install%28%22MAX%22%2C%20%22100%22%29%3B%20install%28%22MIN%22%2C%20%220%22%29%3B%0A%20%20%20%20char%20%2Ar%3B%0A%20%20%20%20r%20%3D%20lookup%28%22MAX%22%29%3B%20printf%28%22MAX%3D%25s%5Cn%22%2C%20r%20%3F%20r%20%3A%20%22undef%22%29%3B%0A%20%20%20%20r%20%3D%20lookup%28%22MIN%22%29%3B%20printf%28%22MIN%3D%25s%5Cn%22%2C%20r%20%3F%20r%20%3A%20%22undef%22%29%3B%0A%20%20%20%20r%20%3D%20lookup%28%22X%22%29%3B%20%20%20printf%28%22X%3D%25s%5Cn%22%2C%20%20%20r%20%3F%20r%20%3A%20%22undef%22%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
