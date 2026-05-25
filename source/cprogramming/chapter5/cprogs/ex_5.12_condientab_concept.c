/* Concept: entab accumulates spaces; emits tab when tab stop reached */
#include <stdio.h>
int main(void) {
    int tabstop[9] = {0,0,0,0,1,0,0,0,1};
    char s[] = "    x"; /* 4 spaces then x */
    int i = 0, col = 0, spaces = 0, c;
    while ((c = (unsigned char)s[i++])) {
        if (c == ' ') {
            spaces++; col++;
            if (col <= 8 && tabstop[col]) { putchar('\t'); spaces = 0; }
        } else {
            while (spaces-- > 0) putchar(' ');
            spaces = 0;
            putchar(c); col++;
        }
    }
    putchar('\n');
    return 0;
}
