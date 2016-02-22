/*Write a program that prints its input one word per line.*/
#include <stdio.h>
#define IN 1
#define OUT 0

/* This program counts the number of lines, characters and words */
main (){
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
