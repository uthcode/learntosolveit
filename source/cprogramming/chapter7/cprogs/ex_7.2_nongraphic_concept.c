/* Concept: non-graphic (control) chars printed as \ooo octal escapes */
#include <stdio.h>
#include <ctype.h>
int main(void) {
    char s[] = "a\tb\n";
    int i = 0, c;
    while ((c = (unsigned char)s[i++])) {
        if (iscntrl(c) || c == ' ')
            printf("\\%03o", c);
        else
            putchar(c);
    }
    putchar('\n');
    return 0;
}
