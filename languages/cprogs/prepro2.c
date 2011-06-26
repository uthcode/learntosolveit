/* ## preprocessor operator */

#include<stdio.h>

#define paste(front,back)  front ## back

int main(void)
{
	int i=paste(10,50);
	printf("%d",i);
	
	return 0;
}

