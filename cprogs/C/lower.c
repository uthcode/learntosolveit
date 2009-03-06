/* lower: convert the input to lower case */

#include<stdio.h>
#include<ctype.h>

int main(void)
{
	int c;

	while((c=getchar()) != EOF)
		putchar(tolower(c));
	
	return 0;
}


