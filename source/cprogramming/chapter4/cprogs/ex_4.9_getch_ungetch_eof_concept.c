/* Concept: int buffer for ungetch/getch so EOF (-1) can be pushed back */
#include <stdio.h>
#define BUFSIZE 4
int buf[BUFSIZE];
int bufp = 0;
int getch(void) { return bufp > 0 ? buf[--bufp] : EOF; }
void ungetch(int c) { if (bufp < BUFSIZE) buf[bufp++] = c; }
int main(void) {
    ungetch('*');
    ungetch('H');
    int c;
    while ((c = getch()) != EOF) putchar(c);
    putchar('\n');
    return 0;
}
