/* Concept: replace tab with spaces to align to tab stops */
#include <stdio.h>
#define TABINC 4
int main(void) {
    char s[] = "a\tb\n";
    int nb, pos = 1, i = 0, c;
    while ((c = (int)(unsigned char)s[i++])) {
        if (c == '\t') {
            nb = TABINC - ((pos-1) % TABINC);
            while (nb > 0) { putchar('#'); ++pos; --nb; }
        } else if (c == '\n') { putchar(c); pos = 1; }
        else { putchar(c); ++pos; }
    }
    return 0;
}
