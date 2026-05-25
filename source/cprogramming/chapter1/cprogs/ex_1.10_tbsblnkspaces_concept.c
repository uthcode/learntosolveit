/* Concept: replace tab/backspace/backslash with visible two-char sequences */
#include <stdio.h>
int main(void) {
    char s[] = "a\tb\n";
    int i = 0, c;
    while ((c = (unsigned char)s[i++])) {
        if      (c == '\t') { putchar('\\'); putchar('t'); }
        else if (c == '\b') { putchar('\\'); putchar('b'); }
        else if (c == '\\') { putchar('\\'); putchar('\\'); }
        else                  putchar(c);
    }
    return 0;
}
