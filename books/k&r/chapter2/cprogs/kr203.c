/**
Write the function htoi(s) , which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The
allowable digits are 0 through 9, a through f, and A through F .
**/

#include<stdio.h>
#define MAXLINE 100

#define YES 1
#define NO 0

int getline(char line[],int maxline);
int htoi(char s[]);

int main(void)
{
	char line[MAXLINE];
	int value;

	getline(line,MAXLINE);
	value=htoi(line);

	printf("The value of %s is %d",line,value);

	return 0;
}

int getline(char s[],int lim)
{
	int c,i;

	for(i=0;i<lim-1 &&(c=getchar())!=EOF && c!='\n';++i)
		s[i] =c;
	if(c=='\n')
	{
		s[i] =c;
		++i;
	}
	s[i] = '\0';

	return i;
}

int htoi(char s[])
{
	int hexdigit,i,inhex,n;
	i = 0;
	if( s[i] == '0')
	{
		++i;
		if(s[i] == 'x' || s[i] == 'X')
			++i;
	}

	n = 0;
	inhex = YES;

	for(;inhex==YES;++i)
	{
		if(s[i] >='0' && s[i] <='9')
			hexdigit= s[i] - '0';
		else if(s[i] >='a' && s[i] <='f')
			hexdigit= s[i] -'a' + 10;
		else if(s[i] >='A' && s[i] <='F')
			hexdigit= s[i] -'A' + 10;
		else
			inhex = NO;

		if(inhex == YES)
			n = 16 * n + hexdigit;
	}
	return n;
}
