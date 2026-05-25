/* Concept: count digits, whitespace, and other chars */
#include <stdio.h>
int main() {
    char s[] = "hi 42";
    int i, nwhite = 0, nother = 0;
    int ndigit[10];
    for (i = 0; i < 10; ++i) ndigit[i] = 0;
    for (i = 0; s[i]; ++i) {
        int c = (unsigned char)s[i];
        if (c >= '0' && c <= '9') ++ndigit[c-'0'];
        else if (c == ' ' || c == '\t') ++nwhite;
        else ++nother;
    }
    printf("digits =");
    for (i = 0; i < 10; ++i) printf(" %d", ndigit[i]);
    printf(", white=%d, other=%d\n", nwhite, nother);
}
