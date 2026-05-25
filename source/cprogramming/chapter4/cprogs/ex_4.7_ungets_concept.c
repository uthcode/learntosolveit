/* Concept: ungets() pushes string chars onto int buf[] in reverse order */
#include <stdio.h>
#define BUFSIZE 4
int buf[BUFSIZE];
int bufp = 0;
void ungetch(int c) { if (bufp < BUFSIZE) buf[bufp++] = c; }
int  getch(void)    { return (bufp > 0) ? buf[--bufp] : -1; }
void ungets(char s[]) {
    int i = 0;
    while (s[i]) i++;
    while (i > 0) ungetch((unsigned char)s[--i]);
}
int main(void) {
    ungets("hi");
    int c;
    while ((c = getch()) != -1) putchar(c);
    putchar('\n');
    return 0;
}
