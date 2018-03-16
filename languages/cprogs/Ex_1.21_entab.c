/**
 *
 * Exercise 1.21 - Write a Program entab that replaces strings of blanks by
 * the minimum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab.
 *
 **/

#include<stdio.h>

#define TABINC 8

int main(void)
{
	int nb,nt,pos,c;
	
	nb = 0;
	nt = 0;
	
	for(pos=1;(c=getchar())!=EOF;++pos)
		if( c == ' ')
		{
			if((pos % TABINC) != 0)
				++nb;
			else
			{
				nb = 0;
				++nt;
			}
		}
		else 
		{
			for( ; nt > 0 ; --nt)
				putchar('\t');
			if( c == '\t')
				nb = 0;
			else
				for( ; nb > 0; --nb)
					putchar(' ');
			
			putchar(c);
			
			if(c == '\n')
				pos = 0;
			else if ( c == '\t')
				pos = pos + ( TABINC - (pos -1) % TABINC) - 1;
		}

	return 0;
}
