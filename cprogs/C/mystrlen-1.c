#include<stdio.h>

int mystrlen(char *);

int main(void)
{
	char *s="string length program;pointer version"; 
	int len;

	len=mystrlen(s);

	printf("%d",len);
}

/* strlen: string length program pointer version */

int mystrlen(char *s)
{
	char *p =s;

	while(*p != '\0')
		p++;

	return p - s;
}



