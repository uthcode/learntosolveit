/**
 * Exercise 4.9 of The C Programming Language by Brian Kernighan and Dennis
 * Ritchie
 *
 * Our getch and ungetch do not handle a pushed-back EOF correctly.
 *
 * Decide what their properties ought to be if an EOF is pushed back, then
 * implement your design.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

char buf[BUFSIZE];

int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int main(int argc, char *argv[]) {
    int c;
    c = '*';

    while ((c = getch()) != EOF) {
        putchar(c);
    }

    return 0;
}
