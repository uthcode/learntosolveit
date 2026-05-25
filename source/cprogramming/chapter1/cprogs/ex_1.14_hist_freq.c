/**
 *
 * Histogram of Frequency of Different Characters in Input
 *
 **/

#include <stdio.h>
static const char *_input = "hello world\n";
static int _pos = 0;
#define getchar() (_input[_pos] ? (int)(unsigned char)_input[_pos++] : EOF)

#define TOTAL_CHARS 128 /* Total Number of characters is 128: 0 - 127 */

int main(void) {
    int c, i, j;

    int _char[TOTAL_CHARS];

    for (i = 0; i < TOTAL_CHARS; ++i) {
        _char[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        _char[c] = _char[c] + 1;
    }

    for (i = 0; i < TOTAL_CHARS; ++i) {
        putchar(i);

        for (j = 0; j < _char[i]; ++j)
            putchar('*');

        putchar('\n');
    }
    return 0;
}
