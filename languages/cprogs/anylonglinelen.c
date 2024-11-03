/**
 * Program to print the longest line.
 * This program prints the length of any-length line with as much possible
 * text it can hold.
 **/

#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int lim);
void copy(char to[], char from[]);

const char* current_input = "First line of text\nSecond longer line of text\nShort line\nVery very very long line that should demonstrate the behavior of the program with a lengthy input sequence\n";

int main(void) {
    int len, max;
    char line[MAXLINE], maxline[MAXLINE];

    max = 0;
    maxline[0] = '\0';  // Initialize maxline

    while ((len = mgetline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(maxline, line);
        }
    }
    printf("%s", maxline);

    return 0;
}

// Custom getchar replacement that reads from our simulated input
int custom_getchar(void) {
    if (current_input && *current_input) {
        return *current_input++;
    }
    return EOF;
}

int mgetline(char s[], int lim) {
    int i, j, c;

    for (i = 0, j = 0; (c = custom_getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 2) {
            s[i] = c;
            ++j;
        }
    if (c == '\n') {
        s[i] = c;
        ++i;
        ++j;
    }
    s[j] = '\0';

    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}
