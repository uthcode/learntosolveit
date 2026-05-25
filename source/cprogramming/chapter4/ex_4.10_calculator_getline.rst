=============================
4.10 Calculator using getline
=============================

Question
========

An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.

.. coderun:: cprogs/ex_4.10_calculator_getline.c
   :language: c

Explanation
===========

This program uses `_getline` to get the characters and operands from the input
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

Visualize the Full Solution
---------------------------

* https://pythontutor.com/c.html


Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20RPN%20using%20getline%20buffer%20instead%20of%20getch%2Fungetch%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0A%23define%20MAXVAL%2010%0Aint%20sp%20%3D%200%3B%0Adouble%20val%5BMAXVAL%5D%3B%0Avoid%20push%28double%20f%29%20%7B%20if%20%28sp%20%3C%20MAXVAL%29%20val%5Bsp%2B%2B%5D%20%3D%20f%3B%20%7D%0Adouble%20pop%28void%29%20%7B%20return%20sp%20%3E%200%20%3F%20val%5B--sp%5D%20%3A%200.0%3B%20%7D%0Aint%20main%28void%29%20%7B%0A%20%20%20%20%2F%2A%202%203%20%2B%20%3D%205%20%2A%2F%0A%20%20%20%20push%282%29%3B%20push%283%29%3B%0A%20%20%20%20push%28pop%28%29%20%2B%20pop%28%29%29%3B%0A%20%20%20%20printf%28%22%25.8g%5Cn%22%2C%20pop%28%29%29%3B%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
