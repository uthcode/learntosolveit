/* Concept: lastc state collapses multiple blanks into one */
#include <stdio.h>
int main(void) {
    char s[] = "a  b   c";
    int i = 0, c, lastc = 0;
    while ((c = (unsigned char)s[i++])) {
        if (c != ' ' || lastc != ' ')
            putchar(c);
        lastc = c;
    }
    putchar('\n');
    return 0;
}
