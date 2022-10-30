/* a recursive version of revese(s); the string reverse function */

#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int mgetline(char line[], int maxline);
void reverse(char s[]);

int main(void) {
    char s[MAXLINE];

    mgetline(s, MAXLINE);

    reverse(s);

    printf("%s", s);

    return 0;
}

int mgetline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = '\n';

    s[i] = '\0';
}

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
    }

    // the algorithm has finished so we have to set i=0 again
    else {
        i = 0;
    }
}
