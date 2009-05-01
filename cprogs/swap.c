#include<stdio.h>
#include<limits.h>
void swap(int *x,int *y);

int main(void)
{
	int a,b;

	a=INT_MAX;
	b=INT_MIN;

	printf("a=%d\n",a);
	printf("b=%d\n",b);

	printf("swapping...\n");
	swap(&a,&b);

	
	printf("a=%d\n",a);
	printf("b=%d\n",b);

	return 0;
}

void swap(int *x,int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}


