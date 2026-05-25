#include <stdio.h>
static const char *_input = "hello world\n";
static int _pos = 0;
#define getchar() (_input[_pos] ? (int)(unsigned char)_input[_pos++] : EOF)

/* count characters in input; 1st version */
int main() {
    long nc;
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}
