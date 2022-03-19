/**
 *
 * Exercise 1.11 - Write a program that prints its input one word per line.
 *
 * */

//suggesting a newer approach found on internet
//concept is: do nothing if you meet more than 1 blankspaces or tab spaces or newlines or "anti word characters"
#include<stdio.h>
#define CTRL(x) (x & 0x1f)
main()
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


/*
#include <stdio.h>
#define IN 1
#define OUT 0

/* This program counts the number of lines, characters and words */
int main (int argc, char *argv[]) {
	int c,state;
	state = IN;
	while((c=getchar()) != EOF) {
		if(c==' ' || c == '\t')
			state=OUT;
		else if (state == OUT) {
			state=IN;
			putchar('\n');
			putchar(c);

		}
		else
			putchar(c);
	}
}
*/
