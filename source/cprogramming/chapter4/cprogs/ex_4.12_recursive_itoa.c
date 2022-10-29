/**
 * Exercise 4.12 of The C Programming Language by Brian Kernighan and Dennis
 * Ritchie
 *
 * Adapt the ideas of printd to write a recursive version of itoa; that is,
 * convert an integer into a string by calling a recursive routine.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char s[]);

int main(int argc, char *argv[]) {
    int n = 123456789;
    char s[100];
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[]) {
    static int i = 0;
    if (n / 10) {
        itoa(n / 10, s);
    } else {
        if (n < 0) {
            s[i++] = '-';
        }
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}
