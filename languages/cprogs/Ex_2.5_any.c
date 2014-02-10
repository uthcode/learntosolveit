/* Write the function any(s1,s2) which returns the first location in the string
 * s1 where any character from the string s2
   occurs, or -1 if s1 contains no characters from s2. ( The standard library
   function strpbrk does the same job but retuns a pointer to the location */

#include<stdio.h>
#define MAXLINE 1000

int mgetline(char line[],int maxline);
int any(char s1[],char s2[]);

int main(void)
{
	char s1[MAXLINE],s2[MAXLINE];
	int val;

	putchar('s');
	putchar('1');
	mgetline(s1,MAXLINE);

	putchar('s');
	putchar('1');
	mgetline(s2,MAXLINE);

	val = any(s1,s2);

	printf("%d",val);

	return 0;
}

int mgetline(char s[],int lim)
{
	int i,c;
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
		s[i]=c;

	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
}

int any(char s1[],char s2[])
{
	int i,j,next;

	next=1;

	for(i=0;s1[i]!='\0'&& (next);++i)
	{
		for(j=0;s2[j]!='\0'&& (s1[i]!=s2[j]);++j)
			;

		if(s2[j]=='\0')
			next=1;
		else
			next=0;
	}

	if(s1[i]=='\0')
		return -1;
	else
		return i;
}
