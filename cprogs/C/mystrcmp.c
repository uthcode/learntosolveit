#include<stdio.h>
#define MAXLINE 1000

int getline(char s[],int lim);
int mystrcmp(char *s,char *t);

int main(void)
{
	char s[MAXLINE],t[MAXLINE];
	int ret;

	putchar('s');
	putchar(':');
	getline(s,MAXLINE);

	putchar('t');
	putchar(':');
	getline(t,MAXLINE);

	ret=mystrcmp(s,t);

	printf("%d",ret);

	return 0;
}

int getline(char s[],int lim)
{
	int c,i;

	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
		s[i] = c;

	if(c=='\n')
	{
		s[i]=c;
		++i;
	}
	s[i]='\0';

	return i;
}

/* mystrcmp: return <0 if s <t , 0 if s==t, > 0 if s > t */
int mystrcmp(char *s,char *t)
{
	int i;
	
	for(i=0;s[i] == t[i];i++)
		if(s[i] == '\0')
			return 0;
	
	return s[i] - t[i];
}

	
