/**
 * Exercise 1.6 - Verify that the expression getchar() != EOF is 0 or 1
 *
 **/

#include <stdio.h>
static const char *_input = "hello\n";
static int _pos = 0;
#define getchar() (_input[_pos] ? (int)(unsigned char)_input[_pos++] : EOF)

int main(int argc, char *argv[]) {
    int c;

    while ((c = getchar()) != EOF) {
        printf("%d ", c != EOF);
        putchar(c);
    }

    printf("\n%d\n", c != EOF);
}
