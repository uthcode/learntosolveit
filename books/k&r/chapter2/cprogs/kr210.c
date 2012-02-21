/**
Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else.
**/

#include<stdio.h>

int lower(int c);

int main(void)
{
	int c;

	while((c=getchar())!=EOF)
	{
		putchar(lower(c));
	}
}

int lower(int c)
{
	return c>='A' && c<='Z'? c+'a'-'A':c;
}

