/**
 * Exercise 1.9 - Write a Program to copy its input to its output, replacing
 * each string of one or more blanks by a single blank.
 *
 * */

#include<stdio.h>

const char *input = "This  line   has   many    blanks to       be replaced by single   blank";
int input_index = 0;

int custom_getchar(void) {
    if (input[input_index] == '\0') {
        return EOF;
    } else {
        return input[input_index++];
    }
}



#define NONBLANK '-'

int main(void)
{
	int c, lastc;

	lastc = NONBLANK;

	while((c = custom_getchar()) != EOF)
	{
		if(c == ' ')
		{
			if(lastc != ' ')
				putchar(c);
		}
		else
			putchar(c);
		lastc=c;
	}
	return 0;
}
