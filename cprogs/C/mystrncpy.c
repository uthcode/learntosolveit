#include<stdio.h>
#define MAXSIZE 1000
void mystrncpy(char *s,char *t,int n);

int main(void)
{
	
	char s[MAXSIZE];
/*	char *s="This is a string"; */
	char *t="Another String";

	mystrncpy(s,t,10);

	printf("%s",s);

	return 0;
}

void mystrncpy(char *s,char *t,int n)
{
	while(*t && n-- > 0)
		*s++ = *t++;

	while(n-- > 0)
		*s++ = '\0';
}

