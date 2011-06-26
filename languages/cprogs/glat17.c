#include<limits.h>
#include<stdio.h>
unsigned long long int countones(unsigned long long int);
int main(void)
{
	unsigned long long int i,cn;
	
	for(i = 1; i<=(ULLONG_MAX - 1); ++i)
	{
		cn = countones(i);
		if( i == cn)
		{
			printf("%d \n",i);
			fflush(stdout);
		}
	}
	
	return 0;
}

unsigned long long int countones(unsigned long long int i)
{
	static unsigned long long int count = 0;
	int digit;

	while((i/10) >= 1)
	{
		digit = i % 10;

		if(digit == 1)
			count++;
		i /= 10;
	}
	if( i == 1)
		count++;

	return count;
}


