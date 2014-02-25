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


When the program enters the while loop it checks for the condition ** (t[i] !=
'\0')** if the condition is true,  then it enters switch condition where the 1st
case it checks for the number of tabs present in the input.  In the 2nd case it
checks for the number of new lines present in the input and then prints the
output.  In the beginning of the program the function **escape** has two
character arrays namely ** s ** and ** t** When the program finishes checking
for the newlines tabs it stores the data in s and prints it.



.. seealso::

   * :c-suggest-improve:`Ex_3.2_escape.c`
   * :c-better-explain:`Ex_3.2_escape.rst`