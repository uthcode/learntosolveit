/* Concept: two-state machine skips /* ... */ comment text */
#include <stdio.h>
int main(void) {
    char s[] = "a/*b*/c";
    int i = 0, c, in_comment = 0;
    while ((c = (unsigned char)s[i++])) {
        if (!in_comment && c == '/' && s[i] == '*') {
            in_comment = 1; i++;
        } else if (in_comment && c == '*' && s[i] == '/') {
            in_comment = 0; i++;
        } else if (!in_comment) {
            putchar(c);
        }
    }
    putchar('\n');
    return 0;
}
