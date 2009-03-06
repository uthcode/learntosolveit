/* usage of sqrt function 
sqrt() is defined in math.h; takes a double argument and returns a double argument 
COMPILATION: gcc -lm <filename>
*/

#include<stdio.h>
#include<math.h>

int main(void)
{
	double number,sqroot;

	number = 4.0;
	sqroot = sqrt(number);

	printf("Square root is %f",sqroot);

	return 0;
}

