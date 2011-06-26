#include<stdio.h>
int mystrncmp(char *s,char *t,int n);

int main(void)
{
	char *s="This line";
	char *t="This line";
	int ret;

	ret=mystrncmp(s,t,5);
	printf("%d",ret);

	return 0;
}

int mystrncmp(char *s,char *t,int n)
{
	for(;*s==*t;s++,t++)
		if(*s=='\0' || --n <= 0)
			return 0;

	return *s - *t;
}

