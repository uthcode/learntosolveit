/* Fibonacci Numbers Generator */
/* Fibonacci series is formed by adding the latest two numbers to get the next one,starting from 0 and 1 */

#include<stdio.h>

int main(void)
{
	int first,second,next,limit;
	printf("How many Numbers in the Series?");
	scanf("%d",&limit);

	first=0;
	second=1;

	printf("%d,%d",first,second);

	while(limit > 2)  /* 0 and 1 are default and counted */
	{
		next = first + second;
		printf(",%d",next);

		first= second;
		second = next;
	
		--limit;
	}
return 0;
}

	
