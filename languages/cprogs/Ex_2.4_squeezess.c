/**
 * Let us write a version of squeeze(s1,s2) that deletes each character in
 * the string 1 that matches any character in the string s2
 **/

#include<stdio.h>
#define MAXLINE 1000

int mgetline(char line[],int maxline);
void squeeze(char s1[],char s2[]);

int main(void)
{
	char s1[MAXLINE],s2[MAXLINE];
	
	putchar('s');
	putchar('1');
	mgetline(s1,MAXLINE);

	putchar('s');
	putchar('2');
	mgetline(s2,MAXLINE);

	squeeze(s1,s2);

	printf("%s",s1);

	return 0;
}

int mgetline(char s[],int lim)
{
	int i,c;
	
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c != '\n';++i)
		s[i] = c;

	if(c == '\n')
		s[i++] = c;
	
	s[i] = '\0';
}

void squeeze(char s1[],char s2[])
{
	int i,j,k;
	k=0;

	for(i=0;s1[i]!='\0';++i)
	{
		for(j=0; (s1[i]!=s2[j]) && s2[j]!='\0' ;++j)
			;
		if(s2[j]=='\0')
			s1[k++] = s1[i];
	}
	
	s1[k]='\0';
}

