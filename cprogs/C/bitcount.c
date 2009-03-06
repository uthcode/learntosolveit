/* bitcount : count 1 bits in x */
#include<stdio.h>

int bitcount(unsigned x);

int main(void)
{
	printf("%d",bitcount((unsigned)255));

	return 0;
}

int bitcount(unsigned x)
{
	int b;
	
	for(b=0; x!= 0; x >>=1)
		if( x & 01)
			b++;
	return b;
}

