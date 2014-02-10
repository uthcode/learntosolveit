/* function squeeze: deletes all the c from s */

#include<stdio.h>
#define MAXLINE 1000

void squeeze(char s[],int c);
int mgetline(char line[],int maxline);

int main(void)
{
	char line[MAXLINE];
	int c;

	mgetline(line,MAXLINE);

	putchar('#');
	c=getchar();
	
	squeeze(line,c);

	printf("%s",line);
	
	return 0;
}

int mgetline(char s[],int lim)
{
	int i,c;
	
	for(i=0;i<lim-1 && (c=getchar())!=EOF && ( c !='\n');++i)
		s[i] = c;

	if(c == '\n')
		s[i++]=c;
	s[i]='\0';
}

void squeeze(char s[],int c)
{
	int i,j;

	for(i=j=0;s[i]!='\0';++i)
		if(s[i]!=c)
			s[j++]=s[i];

	s[j]='\0';
}
	
