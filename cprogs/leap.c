/* Program for the logic of leap year */

#include<stdio.h>
#define YEAR 3000

int main(void)
{
	if( ((YEAR % 4 == 0) && (YEAR % 100 != 0)) || (YEAR % 400 == 0) )
		printf("The Year is a Leap Year");
	else
		printf("The Year is Not a Leap Year");

	return 0;
}

