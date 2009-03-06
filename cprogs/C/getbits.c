/* getbits: get n bits from the position p */

#include<stdio.h>

unsigned getbits(unsigned x,int p,int n);

int main(void)
{
	printf("%u",getbits((unsigned)8,3,1));
}

unsigned getbits(unsigned x,int p,int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}


