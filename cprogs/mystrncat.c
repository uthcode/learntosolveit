#include<stdio.h>
#define MAXLINE 1000

void mystrncat(char *s,char *t,int n);

int main(void)
{
	char s[MAXLINE];
	char *t="Another line";
	
	putchar('s');	
	putchar(':');
	getline(s,MAXLINE);
	mystrncat(s,t,10);
	printf("%s",s);

	return 0;
}

int getline(char s[],int lim)
{
	int i,c;
	
	for(i=0;i<lim-1 && ((c=getchar())!=EOF) && c !='\n'; ++i)
		s[i]=c;

	if(c=='\n')
	{
		s[i] = c;
		++i;
	}
	s[i]='\0';
}

void mystrncat(char *s,char *t,int n)
{
	void mystrncpy(char *s,char *t,int);
	int mystrlen(char *s);
	
	mystrncpy(s+mystrlen(s),t,n);
}

int mystrlen(char *s)
{
	char *p=s;
	while(*s!='\0')
		++s;
	return s-p;
}

void mystrncpy(char *s,char *t,int n)
{
	while(*t && n-- > 0)
		*s++= *t++;
	
	while(n-- > 0)
		*s++ = '\0';
}

