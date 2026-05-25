/* Concept: count lines, words, characters */
#include <stdio.h>
#define IN 1
#define OUT 0
int main() {
    char s[] = "one two\n";
    int nl = 0, nw = 0, nc = 0, state = OUT, i = 0, c;
    while ((c = (int)(unsigned char)s[i++])) {
        ++nc;
        if (c == '\n') ++nl;
        if (c == ' ' || c == '\n' || c == '\t') state = OUT;
        else if (state == OUT) { state = IN; ++nw; }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
