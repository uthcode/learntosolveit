/* Program to print the longest line.
	This program prints the length of any-length line with as much possible text it can hold */

#include<stdio.h>
#define MAXLINE 1000

int getline(char line[],int lim);
void copy(char to[],char from[]);

int main(void)
{
	int len,max;
	char line[MAXLINE],maxline[MAXLINE];

	max = 0;

	while((len=getline(line,MAXLINE)) > 0)
	{
		printf("%d\t%s",len,line);
		if(len > max)
		{
			max=len;
			copy(maxline,line);
		}
	}
	printf("%s",maxline);

return 0;
}

int getline(char s[],int lim)
{
	int i,j,c;

	for(i=0,j=0;(c=getchar())!=EOF && c!= '\n';++i)
		if( i < lim-2 )
		{
			s[i] = c;
			++j;
		}
		if( c == '\n')
		{
			s[i] = c;
			++i;
			++j;
		}
		s[j] = '\0';
		
	return i;
}

void copy(char to[],char from[])
{
	int i;

	i=0;

	while((to[i]=from[i]) != '\0')
		++i;
}

