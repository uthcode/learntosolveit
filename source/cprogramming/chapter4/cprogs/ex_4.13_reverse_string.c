/**
 * a recursive version of reverse(s); the string reverse function
 **/

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void reverse(char s[]) {
    static int i = 0;
    static int len;

    int j;
    char c;

    if (i == 0) {
        len = strlen(s);
    }

    j = len - (i + 1);

    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        reverse(s);
    } else {
        // the algorithm has finished so we have to set i=0 again
        i = 0;
    }
}

int mgetline(char line[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
        line[i++] = '\n';

    line[i] = '\0';
}

int main(void) {
    char s[MAXLINE];

    mgetline(s, MAXLINE);

    reverse(s);

    printf("%s", s);

    return 0;
}