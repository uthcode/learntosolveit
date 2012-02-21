/**
Write a program to remove all comments from a C program. Don't forget to handle
quoted strings and character constants properly. C comments do not nest.
**/

#include<stdio.h>

void rcomment(int c);
void incomment(void);
void echo_quote(int c);

int main(void)
{
	int c,d;

	while((c=getchar())!=EOF)
		rcomment(c);

	printf(" To Check /* Quoted String */ \n");
	d = 'how';
	return 0;
}

void rcomment(int c)
{
	int d;
	if( c == '/')
	{
		if((d=getchar())=='*')
		 incomment();
		else if( d == '/')
		{
			putchar(c);
			rcomment(d);
		}
		else
		{
			putchar(c);
			putchar(d);
		}
	}
	else if( c == '\''|| c == '"')
		echo_quote(c);
	else
		putchar(c);
}

void incomment()
{
	int c,d;

	c = getchar();
	d = getchar();

	while(c!='*' || d !='/')
	{
		c =d;
		d = getchar();
	}
}

void echo_quote(int c)
{
	int d;

	putchar(c);
	while((d=getchar())!=c)
	{
		putchar(d);
		if(d = '\\')
			putchar(getchar());
	}
	putchar(d);
}
