#include <stdio.h>
#define MAXLINE 1000

void escape(char s[], char t[]) {
    int i, j;

    i = j = 0;

    while (t[i] != '\0') {
        switch (t[i]) {
            case '\t':
                s[j] = '\\';
                ++j;
                s[j] = 't';
                break;
            case '\n':
                s[j] = '\\';
                ++j;
                s[j] = 'n';
                break;
            default:
                s[j] = t[i];
                break;
        }
        ++i;
        ++j;
    }

    s[j] = '\0';
}

int mgetline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
        s[i] = c;

    s[i] = '\0';
}

int main(void) {
    char s[MAXLINE], t[MAXLINE];

    mgetline(t, MAXLINE);

    escape(s, t);

    printf("%s", s);

    return 0;
}