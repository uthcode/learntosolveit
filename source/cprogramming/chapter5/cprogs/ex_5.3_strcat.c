#include<stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int lim);

void mystrcat(char *, char *);

int main(void) {
    int len;
    char s[MAXLINE], t[MAXLINE];

    putchar('s');
    putchar(':');
    mgetline(s, MAXLINE);

    putchar('t');
    putchar(':');
    mgetline(t, MAXLINE);

    mystrcat(s, t);

    printf("%s", s);

    return 0;
}

int mgetline(char line[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

void mystrcat(char *s, char *t) {
    while (*s != '\0')
        s++;
    s--;             /* goes back to \0 char */
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

