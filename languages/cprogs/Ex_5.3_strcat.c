#include<stdio.h>
#define MAXLINE 1000

int mgetline(char line[],int maxline);
void mystrcat(char *,char *);

int main(void)
{
	int len;
	char s[MAXLINE],t[MAXLINE];

	putchar('s');
	putchar(':');
	mgetline(s,MAXLINE);
	
	putchar('t');
	putchar(':');
	mgetline(t,MAXLINE);
	
	mystrcat(s,t);

	printf("%s",s);

	return 0;
}

int mgetline(char s[],int lim)
{
	int c,i;
	
	for(i=0;i<lim-1 && (c=getchar()) !=EOF && c!='\n';++i)
		s[i] = c;
	
	if(c == '\n')
	{
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';

	return i;
}

void mystrcat(char *s,char *t)
{
	while(*s!='\0')
		s++;
		s--;
	while((*s=*t)!='\0')
	{	s++;
		t++;
	}
}

