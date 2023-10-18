/**
 * Exercise 1.19 - Write a function reverse that reverses the character
 * string s; use it to write a program that reverses its input a line at a time.
 *
 **/

#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int lim);

void reverse(char rline[]);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = _getline(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

int _getline(char line[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

void reverse(char rline[]) {
    int i, j;
    char temp;

    for (i = 0; rline[i] != '\0'; ++i);

    --i;

    if (rline[i] == '\n')
        --i;

    j = 0;

    while (j < i) {
        temp = rline[j];
        rline[j] = rline[i];
        rline[i] = temp;
        --i;
        ++j;
    }
}
