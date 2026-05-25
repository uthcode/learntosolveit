/* Concept: replace blanks with tabs at tab stop boundaries */
#include <stdio.h>
#define TABINC 4
int main(void) {
    char s[] = "a   b\n";
    int nb = 0, nt = 0, pos = 1, i = 0, c;
    for (; (c = (int)(unsigned char)s[i++]); ++pos)
        if (c == ' ') {
            if ((pos % TABINC) != 0) ++nb;
            else { nb = 0; ++nt; }
        } else {
            for (; nt > 0; --nt) putchar('\t');
            if (c == '\t') nb = 0;
            else for (; nb > 0; --nb) putchar(' ');
            putchar(c);
            if (c == '\n') pos = 0;
        }
    return 0;
}
