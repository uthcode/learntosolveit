===================================================
5.3 strcat(s,t) copies the string t to the end of s
===================================================

Question
========

Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.

.. literalinclude:: cprogs/ex_5.3_strcat.c
   :language: c
   :tab-width: 4


Explanation
===========

This is a string concatenation program using pointers. The function mystrcat is
defined to take two strings as character pointers `mystrcat(char *s, char *t)`
and this function returns the concatenated string in `s` itself.

The way it does is, the position in `s` is advanced till we meet a `\0`
character and then we append the characters from the string `t` to `s`, starting
from the `\0` character till we hit the end of the string `t` which is a `\0`
again.



::

   void mystrcat(char *s,char *t)
   {
	   while(*s!='\0')
	       s++;
	   s--; 		     /* goes back to \0 char */
	   while((*s=*t)!='\0')
	   {	
	      s++;
	      t++;
	   }
   }


The construct `while((*s=*t)!='\0')` assigns the character in `t` to `s` and then checks if the character is `\0`.





Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20pointer%20walks%20to%20end%20of%20s%2C%20then%20copies%20t%20char-by-char%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Avoid%20mystrcat%28char%20%2As%2C%20char%20%2At%29%20%7B%0A%20%20%20%20while%20%28%2As%29%20s%2B%2B%3B%0A%20%20%20%20while%20%28%28%2As%2B%2B%20%3D%20%2At%2B%2B%29%20%21%3D%20%27%5C0%27%29%3B%0A%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20char%20s%5B10%5D%20%3D%20%22hi%22%3B%0A%20%20%20%20mystrcat%28s%2C%20%22%21%21%22%29%3B%0A%20%20%20%20printf%28%22%25s%5Cn%22%2C%20s%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
