#include<stdio.h>

int mygetchar(void);

int main(void)
{
	int c;
	c = mygetchar();

	printf("%c",c);

	return 0;
}

int mygetchar(void)
{
	char c;
	return (read(0,&c,1)==1)?(unsigned char)c:EOF;
}

