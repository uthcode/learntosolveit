/* Concept: fold long line at word boundary */
#include <stdio.h>
#define MAXCOL 10
int main(void) {
    char s[] = "hi there ok";
    int i = 0, col = 0;
    while (s[i]) {
        if (col >= MAXCOL && s[i] == ' ') { putchar('\n'); col = 0; i++; continue; }
        putchar(s[i++]);
        col++;
    }
    putchar('\n');
    return 0;
}
