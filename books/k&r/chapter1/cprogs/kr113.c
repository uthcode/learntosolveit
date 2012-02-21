/**
Write a program to print a histogram of the lengths of words in its input. It
is easy to draw the histogram with the bars horizontal; a vertical orientation
is more challenging.
**/


#include<stdio.h>

int horizontal(void)
{
	int c;

	while((c=getchar())!=EOF)
	{

		if( c == ' ' || c == '\n' || c == '\t')
			putchar('\n');
		else
			putchar('*');
	}
return 0;
}


/* Vertical Histogram of words in a Sentence */

#include<stdio.h>
#define MAXWL 20  /* Maximum length of a word */
#define MAXNO 25 /* Maximum No of words in a sentence */

int main(void)
{
	int word[MAXNO];
	int i,c,j,nc,nw;

	for(i=0;i<MAXNO;++i)
		word[i]=0;

	nc = nw = 0;

	while( (c=getchar()) != EOF)
	{
		++nc;
		if( c ==' ' || c =='\n' || c =='\t')
		{
			word[nw] = nc -1; /* -1 for excluding the space in the word length */
			++nw;
			nc = 0; /* resetting the word-length for the next word */
		}
	}

	for( i = MAXWL; i >= 1; --i)
	{
		for(j=0;j <= nw;++j)
		{
			if( i <= word[j])
				putchar('*');
                        else
				putchar(' ');
			}
	putchar('\n');
	}

return 0;
}

