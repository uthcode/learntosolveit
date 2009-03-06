/* rot13 algorithm. Very Simple and Interesting */

#include<stdio.h>
#define ROT 13

int main(void)
{
	int c,e;

	while((c=getchar())!=EOF)
	{
		if(c >='A' && c <='Z')
		{
			if((e = c + ROT) <= 'Z')
				putchar(e);
			else
			{
				   e = c - ROT;
				putchar(e);
			}
		}
		else if(c >='a' && c <='z')
		{
			if((e= c + ROT) <= 'z')
				putchar(e);
			else
			{
				e = c - ROT;
				putchar(e);
			}
		}
		else
			putchar(c);
	}

return 0;
}

