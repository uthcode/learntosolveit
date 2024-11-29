#include <stdio.h>
#define MAXLINE 100

void expand(char s1[], char s2[]) {
    int i, j, c;

    i = j = 0;

    while ((c = s1[i++]) != '\0')
        if (s1[i] == '-' && s1[i + 1] >= c) {
            i++;
            while (c < s1[i])
                s2[j++] = c++;
        } else
            s2[j++] = c;

    s2[j] = '\0';
}

int mgetline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
}

int main(void) {
    char s1[MAXLINE], s2[MAXLINE];

    mgetline(s1, MAXLINE);

    expand(s1, s2);

    printf("%s", s2);

    return 0;
}