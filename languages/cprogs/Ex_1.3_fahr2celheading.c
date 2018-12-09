/***
 *
 * Exercise 1-3. Modify the temperature conversion program, 
 * Fahrenheit to Celsius, to print a heading above the table.
 *
 * print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; 
 * floating-point version.
 *
 ***/

#include<stdio.h>

int main(void)
{
	printf("A program print Fahrenheit-Celsius\n");

	float fahr, celsius;
        int lower, upper, step;
  
	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	
        printf("Fahr\tCelsius\t \n");
      
	while(fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr - 32.0);
                printf("%4.0f %10.1f\n", fahr, celsius);
                fahr = fahr + step;
	}

	return 0;
}
