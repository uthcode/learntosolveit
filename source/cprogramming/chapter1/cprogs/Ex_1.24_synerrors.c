/**
 *
 * Exercise 1.24 - Syntax Errors.
 *
 * Program to check rudimentary syntax errors like un-match braces,
 * brackets or parenthesis.
 *
 **/

#include<stdio.h>

int brace,brack,paren;

void incomment();
void inquote(int c);
void search(int c);

int main(void)
{
	int c;
	
	extern int brace, brack, paren;

	while((c=getchar())!=EOF)
		if( c == '/')
			if((c=getchar())== '*')
				incomment();
			else 
				search(c);
		else if( c == '\'' || c == '"')
			inquote(c);
		else
			search(c);

	if( brace < 0)
	{
		printf("Unmatched Braces\n");
		brace = 0;
	}	
	else if( brack < 0)
	{
		printf("Unmatched brackets\n");
		brack = 0;
	}
	else if( paren < 0)
	{
		printf("Unmatched parenthesis\n");
		paren = 0;
	}
	
	if(brace > 0)
		printf("Unmatched braces\n");
	else if(brack > 0)
		printf("Unmatched brackets\n");
	else if(paren > 0)
		printf("Unmatched parenthesis\n"); 

	return 0;
}

void incomment()
{
	int c,d;
	
	c = getchar();
	d = getchar();

	while(c != '*' || d != '/')
	{
		c = d;
		d = getchar();
	}
}

void inquote(int c)
{
	int d;

	putchar(c);

	while((d=getchar())!=c)
		if( d == '\\')
			getchar();
}

void search(int c)
{
	extern int brace,brack,paren;

	if ( c == '{')
		--brace;
	else if ( c == '}')
		++brace;
	else if( c == '[')
		--brack;
	else if( c == ']')
		++brack;
	else if( c == '(')
		--paren;
	else if( c == ')')
		++paren;
}


					
