/*Write a program that prints its input one word per line.*/
#include<stdio.h>

int main() {
	int c, ccount;
	ccount = 0;
	while((c = getchar()) != EOF) {
		if(c == '\n' || c == '\t' || c == ' ') {
			if (ccount > 0) {
				putchar('\n');
			}
			ccount = 0;
		} else {
			ccount++;
			putchar(c);
		}
	}	
}
