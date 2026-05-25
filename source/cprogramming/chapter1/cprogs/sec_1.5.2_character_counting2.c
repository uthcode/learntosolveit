#include <stdio.h>
static const char *_input = "hello world\n";
static int _pos = 0;
#define getchar() (_input[_pos] ? (int)(unsigned char)_input[_pos++] : EOF)

/* count characters in input; 2nd version */
int main() {
    double nc;
    for (nc = 0; getchar() != EOF; ++nc);
    printf("%.0f\n", nc);
}
