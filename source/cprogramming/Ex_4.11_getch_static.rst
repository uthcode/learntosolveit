====================================
Exercise 4.11 - getline using static
====================================

Question
========

Modify getop so that it doesn't need to use ungetch. Hint: use an internal
static variable.

.. literalinclude:: ../../languages/cprogs/Ex_4.11_getch_static.c
   :language: c
   :tab-width: 4

.. runcode:: ../../languages/cprogs/Ex_4.11_getch_static.c
   :language: c
   :codesite: ideone

Explaination
============

The point of illustration of this program is the static variable, `lastc`, which
gets initialized once as a static variable and maintains its state at each
invocation.  The `getop` function declares the variable `lastc` and proceeds as
before. It calles `getch` to get the last character and if it is a `EOF` it
returns the EOF, if it a space ignores and if not a number, it returns
immediately and ensures that it parses a valid number.

At the end, it verifies that the character read is not `EOF` and the stores the
last character which was read using `getch` in the `lastc` variable.


::



	int getop(char s[])
	{
		int c,i;
		static int lastc = 0;

		if(lastc == 0)
			c = getch();
		else
		{
			c = lastc;
			lastc = 0;
		}

		while((s[0]=c) == ' ' || c == '\t')
			c = getch();
		
		s[1]='\0';
		
		if(!isdigit(c) && c!= '.')
			return c;
		
		i = 0;
		if(isdigit(c))
			while(isdigit(s[++i] =c=getch()))
				;
		if(c=='.')
			while(isdigit(s[++i] =c=getch()))
				;
		s[i]='\0';
		
		if(c!=EOF)
			lastc=c;

		return NUMBER;
	}

The program execution looks like this.

::

	10 10 +
	        20
	201 305 + 20 *
	        10120




.. seealso::

   * :c-suggest-improve:`Ex_4.11_getch_static.c`
   * :c-better-explain:`Ex_4.11_getch_static.rst`