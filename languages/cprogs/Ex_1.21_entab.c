/* Write a Program entab that replaces strings of blanks by the minimum 
	number of tabs and blanks to acheive the same spacing.
   Use the same tab stops as for detab.
*/
#include<stdio.h>
#define TABINC 8

int main(void)
{
	int nb,nt,pos,c;
	
	nb = 0;
	nt = 0;
	pos = 0;
	
	while((c=getchar())!=EOF) {
		++pos;
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
			
			if(c == '\n' || c == '\t')
				pos = 0;
		}

	return 0;
}

