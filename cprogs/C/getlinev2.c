#include<stdio.h>
#define MAXLINE 1000
int getline(char *s,int line);

int main(void)
{
	char s[MAXLINE];
	int ret;

	ret=getline(s,MAXLINE);
	
	printf("%s",s);
	printf("%d",ret);

	return 0;
}

int getline(char *s,int lim)
{
	int c;
	char *t=s;

	while(--lim > 0 && (c=getchar())!=EOF && c!='\n')
		*s++=c;
	
	if(c=='\n')
		*s++=c;
	
	*s='\0';

	return s-t;
}

	
