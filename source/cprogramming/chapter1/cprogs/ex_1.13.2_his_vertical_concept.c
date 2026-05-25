/* Concept: vertical histogram of word lengths */
#include <stdio.h>
int main(void) {
    int word[2] = {0};
    char s[] = "ab cd\n";
    int nc = 0, nw = 0, i, j;
    for (i = 0; s[i]; ++i) {
        ++nc;
        if (s[i] == ' ' || s[i] == '\n') { word[nw++] = nc-1; nc = 0; }
    }
    for (i = 2; i >= 1; --i) {
        for (j = 0; j < nw; ++j) putchar(i <= word[j] ? '*' : ' ');
        putchar('\n');
    }
    return 0;
}
