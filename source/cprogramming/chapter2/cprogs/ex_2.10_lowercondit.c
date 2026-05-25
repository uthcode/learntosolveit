/* Function lower(c) using conditional expression */

#include <stdio.h>
static const char *_input = "Hello World\n";
static int _pos = 0;
#define getchar() (_input[_pos] ? (int)(unsigned char)_input[_pos++] : EOF)

int lower(int c);

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }
}

int lower(int c) { return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c; }
