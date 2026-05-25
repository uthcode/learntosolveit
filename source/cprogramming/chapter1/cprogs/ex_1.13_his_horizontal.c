/**
 *
 * Print a horizontal histogram of words in the input.
 *
 **/

#include <stdio.h>
static const char *_input = "hello world\n";
static int _pos = 0;
#define getchar() (_input[_pos] ? (int)(unsigned char)_input[_pos++] : EOF)

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            putchar('\n');
        else
            putchar('*');
    }
    return 0;
}
