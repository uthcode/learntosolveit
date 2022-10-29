/**
 * Exercise 4.7 of The C Programming Language by Brian Kernighan and Dennis
 * Ritchie
 *
 * Write a routine ungets(s) that will push back an entire string onto the
 * input. Should ungets know about buf and bufp, or should it just use ungetch?
 *
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
#define MAXLINE 1000

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
void ungets(char s[]);
int mgetline(char s[], int lim);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int len;

    while ((len = mgetline(line, MAXLINE)) > 0) {
        ungets(line);
        while ((len = mgetline(line, MAXLINE)) > 0) {
            printf("%s", line);
        }
    }
    return 0;
}

int mgetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

void ungets(char s[]) {
    int len = strlen(s);
    while (len > 0) {
        ungetch(s[--len]);
    }
}
