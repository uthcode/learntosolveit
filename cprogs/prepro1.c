/* # operator in preprocessor */
#include<stdio.h>

#define dprint(expr)    printf(#expr " = %d \n",expr);

int main(void)
{
	int x=10,y=5;
	
	dprint(x/y);

	return 0;
}

