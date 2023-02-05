/* Function lower(c) using conditional expression */

#include <stdio.h>

int lower(int c);

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }
}

int lower(int c) { return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c; }
