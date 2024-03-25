/* getint: get next integer from input to *pn.
 * Free form input conversion routine */

#include<stdio.h>
#include<ctype.h>

#define SIZE 1000
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


int getint(int *pn)
{
	int c,sign;

	while(isspace(c=getch()))
		;

	if(!isdigit(c) && c !=EOF && c!='+' && c!='-')
	{
		ungetch(c); /* it's not a number */
		return -1; /* -1 will end the program directly */
	}

	sign = (c == '-') ? -1 : 1;

	if(c=='+' || c=='-')
		c = getch();
	/* This snippet avoids to treat a '+' or '-' not followed by a digit as a valid representation of zero */
  	if( !isdigit( c ) )
    		return 0;
	for(*pn = 0; isdigit(c);c=getch())
		*pn = 10 * *pn + (c-'0');

	*pn *= sign;

	if(c!=EOF)
		ungetch(c);

	return c;
}

int main(void)
{
	int n,s,array[SIZE];
	
	for(n=0;n<SIZE && getint(&array[n]) !=EOF; n++){
	   printf("storing in n = %d, getint %d\n", n, array[n]);
	}

	printf("storing in n = %d, getint %d\n", n, array[n]);

	for(s=0;s<=n; s++)
		printf("%d",array[s]);

	return 0;
}
