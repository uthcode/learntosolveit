/* Getint with the provision to handle + or - sign and pushback a character */

#include<stdio.h>
#include<ctype.h>

#define SIZE 1000

int getch(void);
void ungetch(int);

int main(void)
{
	int n,array[SIZE],getint(int *);

	for(n=0;n<SIZE && getint(&array[n]) != EOF;n++)
		;

	for(; n>=0;n--)
		printf("%d",array[n]);

	return 0;
}

int getint(int *pn)
{
	int c,d,sign;
	
	while(isspace(c=getch()))
		;
	if(!isdigit(c) && c != EOF && c!= '+' && c!= '-')
	{
		ungetch(c);
		return 0;
	}
	
	sign= (c == '-') ? -1 : 1;
	
	if(c == '+' || c == '-')
	{
		d = c; /* remember the signed character */
	
		if(!isdigit(c=getch()))
		{
			if(c!=EOF)
				ungetch(c);
			ungetch(d);
			return d;
		}
	}

	for(*pn=0;isdigit(c);c=getch())
		*pn = 10 * *pn + (c-'0');

	*pn *= sign;

	if( c != EOF)
			ungetch(c);
	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0)? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++]=c;
}
		 	
