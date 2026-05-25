/* Concept: horizontal histogram — print * per char, newline at word boundary */
#include <stdio.h>
int main(void) {
    char s[] = "hi\n";
    int i = 0, c;
    while ((c = (int)(unsigned char)s[i++])) {
        if (c == ' ' || c == '\n' || c == '\t') putchar('\n');
        else putchar('*');
    }
    return 0;
}
