======
atoiv2
======

*atoiv2.c* 

.. literalinclude:: ../../languages/cprogs/atoiv2.c
   :language: c
   :tab-width: 4


.. raw:: html

   <iframe width="100%" height="500" frameborder="0" src="http://pythontutor.com/iframe-embed.html#code=/*%20Ex5.6%20*/%0A%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cctype.h%3E%0A%0Aint%20atoiv2%28char%20*%29%3B%0A%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20*s%20%3D%20%221234%22%3B%0A%20%20%20%20int%20ret%3B%0A%0A%20%20%20%20ret%20%3D%20atoiv2%28s%29%3B%0A%0A%20%20%20%20printf%28%22%25d%22,%20ret%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D%0A%0Aint%20atoiv2%28char%20*s%29%20%7B%0A%20%20%20%20int%20n,%20sign%3B%0A%0A%20%20%20%20for%20%28%3B%20isspace%28*s%29%3B%20s%2B%2B%29%20%20%20%20/*%20skip%20white%20space%20*/%0A%20%20%20%20%20%20%20%20%3B%0A%20%20%20%20sign%20%3D%20%28*s%20%3D%3D%20'-'%29%20%3F%20-1%20%3A%201%3B%0A%0A%20%20%20%20if%20%28*s%20%3D%3D%20'%2B'%20%7C%7C%20*s%20%3D%3D%20'-'%29%0A%20%20%20%20%20%20%20%20s%2B%2B%3B%0A%20%20%20%20for%20%28n%20%3D%200%3B%20isdigit%28*s%29%3B%20s%2B%2B%29%0A%20%20%20%20%20%20%20%20n%20%3D%2010%20*%20n%20%2B%20*s%20-%20'0'%3B%0A%0A%20%20%20%20return%20sign%20*%20n%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D"> </iframe>


.. seealso::

	* :c-suggest-improve:`atoiv2.c`
	* :c-better-explain:`atoiv2.rst`
