========================================
Exercise 4.10 - Calculator using getline
========================================

Question
========

An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.

.. literalinclude:: cprogs/ex_4.10_calculator_getline.c
   :language: c

Explanation
===========

This program uses `mgetline` to get the characters and operands from the input
and and proceeds with the RPN calculator logic.

This is the main part of the program.


::

	/* getop: get next operator or numeric operand */

	int getop(char s[])
	{
		int c,i;

		if(line[li] == '\0')
			if(_getline(line,MAXLINE) == 0)
				return EOF;
			else
				li =0;

		while((s[0] = c = line[li++]) == ' ' || c == '\t')
			;

		s[1] = '\0';

		if(!isdigit(c) && c!= '.')
			return c;

		i = 0;

		if(isdigit(c))
			while(isdigit(s[++i] = c = line[li++]))
				;
		if( c == '.')
			while(isdigit(s[++i] = c = line[li++]))
				;

		s[i] = '\0';

		li--;

		return NUMBER;
	}


From the _getline function, it takes the input in the line character array, and
if if the line is `\0` only, then we define that as EOF and return `EOF`. Then
we assign to `c` the value present at `line` and look for various conditions
like, if line is a space or tab character, we simply skip it. If we encouter c
which is not a digit or not a `.` character, we return `c` immediately.  At the
end if it is valid number, we return a NUMBER, which is then pushed onto the
stack of the RPN calculator.

An example execution will look like this.

::

	10 10 +
	        20
	10.1 20.2 +
	        30.3

Visualize It
============

* https://pythontutor.com/c.html

Try It
======


.. raw:: html

   <iframe frameborder="0" width="100%" height="800px" src="https://replit.com/@learntosolveit/ex410calculatorgetline?embed=true"></iframe>
