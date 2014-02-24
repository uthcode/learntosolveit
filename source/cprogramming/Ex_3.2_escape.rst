========================================================
Exercise 3.2 - escape sequences into the real characters
========================================================

Question
========

Write a function escape(s,t) that converts characters like newline and tab into visible
escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the
other direction as well, converting escape sequences into the real characters.

.. literalinclude:: ../../languages/cprogs/Ex_3.2_escape.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_3.2_escape.c
   :language: c
   :codesite: ideone

Explaination
============

The essence of this program is to make the new-line (\n) and tab(\t) visible in the output of the program.
This is done by:: 

1.		while(t[i] != '\0')
2.		{
3.			switch(t[i])
4.			{
5.				case '\t':
6.						s[j]='\\';
7.						++j;
8.						s[j]='t';
9.						break;
10.				case '\n':
11.						s[j]='\\';
12.						++j;
13.						s[j]='n';
14.						break;
15.				default:
16.						s[j]=t[i];
17.						break;
18.			}
19.			++i;
20.			++j;
21.		}





.. seealso::

   * :c-suggest-improve:`Ex_3.2_escape.c`
   * :c-better-explain:`Ex_3.2_escape.rst`