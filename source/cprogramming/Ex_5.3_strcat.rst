==============================================================
Exercise 5.3 - strcat(s,t) copies the string t to the end of s
==============================================================

Question
========

Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.

.. literalinclude:: ../../languages/cprogs/Ex_5.3_strcat.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_5.3_strcat.c
   :language: c
   :codesite: ideone

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

.. git_changelog::

.. seealso::

   * :c-suggest-improve:`Ex_5.3_strcat.c`
   * :c-better-explain:`Ex_5.3_strcat.rst`
