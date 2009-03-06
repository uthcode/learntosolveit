/* A Progrm for my_atoi() which converts the string to integer */

#include<stdio.h>
#define MAXLINE 1000

int getline(char line[],int maxline);
int my_atoi(char s[]);

int main(void)
{
	int value;
	char line[MAXLINE];
	getline(line,MAXLINE);

	value=my_atoi(line);

	printf("The Integer entered is %d",value);
	
	return 0;
}

int getline(char s[],int lim)
{
	int i,c;
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i]=c;
	if( c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i]=c;
	return i;
}
int my_atoi(char s[])
{
	int i,n;
	
	n = 0;
	
	for(i=0;s[i]>'0' &&s[i]< '9';++i)
		n = 10 * n + ( s[i] - '0');
	
	return n;
}

