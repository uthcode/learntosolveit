=======================================================
Section 4.1 - Find the pattern in the line and print it
=======================================================

Program
=======


.. literalinclude:: ../../languages/cprogs/sec_4.1.c
   :language: c
   :tab-width: 4
   

.. runcode:: ../../languages/cprogs/sec_4.1.c
   :language: c
   :codesite: ideone


Explaination
============

This program searches particular pattern in a given string.  As per the program we are going to search for the pattern **ould** and print the line which has the same.  

Let us say that we give the input as::

	This line would print
	This line will not print

The output would be::

	This line would print

As it contains the pattern **ould**.  The curx of the program is in the strindex function.

::

    int strindex(char s[], char t[])
    {
        int i, j, k;
        for (i = 0; s[i] != '\0'; i++) {
            for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
                ;
            if (k > 0 && t[k] == '\0')
                return i;
        }
        return -1;
     }
     
Here we have the source string in **s** and target string in **t**. We start taking each character in s and starting at the position of the character, we check if the entire target string **t** is present in the string.

The checking for the entire target is present is done by the second for loop and the if statement.::

    for(j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
        ;
    if (k > 0 && t[k] == '\0')
        return i;

In the first for loop we use a temperorary variable k to iterate through and check if the target string **t** is present in **s**. If the target string is entirely present, which is ensured by if statement checking for `\0`, we return the position **i**. 

In the main program, if we find the position greater than 0, we print the line.



.. seealso::

   * :c-suggest-improve:`sec_4.1.c`
   * :c-better-explain:`sec_4.1.rst`
