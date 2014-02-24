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

	while(t[i] != '\0')
    {
        switch(t[i])
        {
            case '\t':
                    s[j]='\\';
                    ++j;
                    s[j]='t';
                    break;
            case '\n':
                    s[j]='\\';
                    ++j;
                    s[j]='n';
                    break;
            default:
                    s[j]=t[i];
                    break;
        }
        ++i;
        ++j;
    }
    
    s[j]='\0';
}




.. seealso::

   * :c-suggest-improve:`Ex_3.2_escape.c`
   * :c-better-explain:`Ex_3.2_escape.rst`