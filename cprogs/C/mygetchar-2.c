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
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n = 0;

	if( n == 0)
	{
		n = read(0,buf,sizeof(buf));
		bufp = buf;
	}

	return (--n >= 0)?(unsigned char)*bufp++:EOF;
}

