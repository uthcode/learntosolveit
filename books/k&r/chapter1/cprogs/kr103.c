/**
Modify the temperature conversion program to print a heading above the table.
**/

#include<stdio.h>

int main()
{
	int lower,upper,step;
	int celsius,fahr;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	while( fahr <= upper)
	{
		celsius =  5 * (fahr - 32) / 9;
		printf("%d\t%d\n",fahr,celsius);
		fahr = fahr + step;
	}

	return 0;
}

