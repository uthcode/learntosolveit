/**
 * Exercise 2.5
 *
 * Write the function any(s1,s2) which returns the first location in the string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains
 * no characters from s2. ( The standard library function strpbrk does
 * the same job but returns a pointer to the location
 *
 **/

#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int lim);

int any(char s1[], const char s2[]);

int main(void) {
    char s1[MAXLINE], s2[MAXLINE];
    int val;

    mgetline(s1, MAXLINE);
    mgetline(s2, MAXLINE);

    val = any(s1, s2);

    printf("%d", val);

    return 0;
}

int mgetline(char line[], int lim) {
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';

    return i;
}

int any(char s1[], const char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return -1;
}
