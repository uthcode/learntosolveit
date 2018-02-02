/**
 *
 * Histogram of Frequency of Different Characters in Input
 *
 **/

#include<stdio.h>

#define TNOCHAR 128  /* Total Number of characters is 128: 0 - 127 */

int main(void)
{
	int c, i, j;

	int _char[TNOCHAR];

	for(i=0; i < TNOCHAR; ++i)
		_char[i] = 0;
	
	while((c=getchar()) != EOF)
		++_char[c];

	for(i=0; i<TNOCHAR; ++i)
	{
		putchar(i);
		
		for(j=0; j < _char[i]; ++j)
			putchar('*');

		putchar('\n');
	}
	return 0;
}
