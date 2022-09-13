/**
 *
 * Exercise 1.11 - Write a program that prints its input one word per line.
 *
 * */

// concept is: do nothing if you meet more than 1 blankspaces or tab spaces or newlines or "anti word characters"

#include <stdio.h>

#define CTRL(x) (x & 0x1f)

int main()
{
	int c;

	while((c = getchar()) != EOF && c != CTRL('d') )
	{
		if(c == ' ' || c == '\t' || c == '\n' || c == '-')
		{
			putchar('\n');

			while((c = getchar()) == ' ' || c == '\t' || c == '\n' || c == '-' )
			{
				; //do nothing // we could actually skip the braces and just enter ; after closing the while's condition brackets
			}
		}
		putchar(c);
	}
}

