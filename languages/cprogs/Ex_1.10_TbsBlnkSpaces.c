/**
 * Exercise 1.10 - Write a Program to copy its input to its output,
 * replacing each tab by \t, each backspace by \b, and each backslash by \\.
 * This makes tabs and backspaces visible in an unambiguous way.
 *
 * */

#include<stdio.h>

const char *input = "This\tis\ta\b\btest\tstring.";
int input_index = 0;

int _getchar(void) {
    if (input[input_index] == '\0') {
        return EOF;
    } else {
        return input[input_index++];
    }
}

int main(void)
{
	int c;

	while((c = _getchar()) != EOF)
	{
		if(c == '\t')
		{
			putchar('\\');
			putchar('t');
		}

		if(c == '\b')
		{
			putchar('\\');
			putchar('b');
		}

		if(c == '\\')
		{
			putchar('\\');
			putchar('\\');
		}

		if(c != '\t' && c != '\b' && c != '\\')
			putchar(c);
	}
	return 0;
}
