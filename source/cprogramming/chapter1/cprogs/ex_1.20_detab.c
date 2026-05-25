/**
 * Exercise 1.20
 *
 * Write a Program detab, which replaces tabs in the input with a proper
 * number of blanks to spaces
 **/

#include <stdio.h>
static const char *_input = "col1\tcol2\tcol3\n";
static int _pos = 0;
#define getchar() (_input[_pos] ? (int)(unsigned char)_input[_pos++] : EOF)

#define TABINC 8

int main(void) {
    int nb, pos, c;

    nb = 0;
    pos = 1;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            nb = TABINC - ((pos - 1) % TABINC);

            while (nb > 0) {
                putchar('#');
                ++pos;
                --nb;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }

    return 0;
}
