/* Concept: IN/OUT state machine counts lines, words, chars */
#include <stdio.h>
#define IN  1
#define OUT 0
int main(void) {
    char s[] = "one two\n";
    int nl = 0, nw = 0, nc = 0, state = OUT, i = 0, c;
    while ((c = (unsigned char)s[i++])) {
        ++nc;
        if (c == '\n') ++nl;
        if (c == ' ' || c == '\n' || c == '\t') state = OUT;
        else if (state == OUT) { state = IN; ++nw; }
    }
    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}
