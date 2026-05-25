#include <stdio.h>
static const char *_input = "line one\nline two\n";
static int _pos = 0;
#define getchar() (_input[_pos] ? (int)(unsigned char)_input[_pos++] : EOF)

/* count lines in input */
int main() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
