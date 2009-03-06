/* Run the "hello, world" program on your system. Experiment with leaving out
 * parts of the program, to see what error messages you get. */

#include <stdio.h>
int main()
{
    printf("Hello, World\n");

/* This is textual question.
   Leave out # in #include you will get: Syntax Error.
   Leave out < and > stdio.h you will get: #include expects <FILENAME> or
   "FILENAME"
   Leave out ( or ) or both in main() you will get a Syntax Error.
   Leave out { in the program, you will get syntax errors of different sorts.
	   error: syntax error before "printf"
	   error: conflicting types for 'printf'
	   note: a parameter list with an ellipsis can't match an empty
	   parameter name list declaration
	   conflicting types for 'printf'
	   warning: data definition has no type or storage class
   Leave out " in the string, it botchs up the entire program.
   Leave out ; in the printf statement, it gives syntax error again.
   Leave out the final '}' it gives the syntax error, quite different from
   leaving out the initial '{'

*/
