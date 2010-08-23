/* Program demonstrates the former getline forloop without && and ||.
Also demonstrates enum data type usage */

#include<stdio.h>
#define MAXLINE 1000

int getline(char line[],int maxline);

int main(void)
{
	char line[MAXLINE];
	
	getline(line,MAXLINE);

	printf("%s",line);

	return 0;
}

int getline(char s[],int lim)
{
	int c,i;
	enum values{NO=0,YES};
	enum values proceed;

	proceed= YES;

	i =0;

	while(proceed == YES)
	{
		if( i > lim - 1)
			proceed = NO;
		else if((c=getchar()) == EOF)
			proceed = NO;
		else if( c == '\n')
			proceed = NO;
		else
		{
			s[i] = c;
			++i;
			proceed = YES;
		}
	}
	if ( c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

		
	


