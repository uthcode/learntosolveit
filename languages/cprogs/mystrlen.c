#include<stdio.h>

int mystrlen(char *);

int main(void)
{
	int len;
	char *s="Hari is my roommate";
	len=mystrlen(s);
	
	printf("%d",len);

	return 0;
}

int mystrlen(char *s)
{
	int n;

	for(n=0; *s !='\0';s++)
		n++;
	
	return n;
}

