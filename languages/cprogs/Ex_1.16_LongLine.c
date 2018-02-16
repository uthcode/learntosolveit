/**
 * Exercise 1.16
 *
 * Write a Program to print the longest line input
 *
 **/

#include<stdio.h>

#define MAXLINE 1000

int mgetline(char line[],int lim);

void copy(char to[],char from[]);


int main(void)
{
	int len,max;
	char line[MAXLINE], maxline[MAXLINE];

	max =0;

	while((len = mgetline(line, MAXLINE)) > 0)
	{
		if(len > max)
		{
			max = len;
			copy(maxline,line);
		}
	}

	if(max>0)
		printf("%s",maxline);
}
	

int mgetline(char s[],int lim)
{
	int i,c;

	for(i=0;i<lim-1 && (c=getchar())!=EOF && c !='\n';++i)
		s[i] = c;

	if(c == '\n')
	{
	s[i] = c;
	++i;
	}

	s[i] = '\0';
	return i;
}

void copy(char to[],char from[])
{
	int i;
	i=0;

	while((to[i]=from[i]) != '\0')
	++i;
}
		
