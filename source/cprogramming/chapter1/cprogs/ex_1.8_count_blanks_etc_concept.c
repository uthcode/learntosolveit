/* Concept: count blanks, tabs, newlines using separate int counters */
#include <stdio.h>
int main(void) {
    char s[] = "a \tb\n";
    int nb = 0, nt = 0, nl = 0, i = 0, c;
    while ((c = (unsigned char)s[i++])) {
        if (c == ' ')  ++nb;
        if (c == '\t') ++nt;
        if (c == '\n') ++nl;
    }
    printf("blanks=%d tabs=%d newlines=%d\n", nb, nt, nl);
    return 0;
}
