/**
 * Exercise 2.3 - htoi program, character to integer program.
 *
 */

#include <stdio.h>

#define MAXLINE 100
#define BASE 16

int mgetline(char line[], int lim);

unsigned int htoi(const char s[], int len);

int main(void) {
    char line[MAXLINE];
    int len;
    unsigned int value;

    len = mgetline(line, MAXLINE);
    value = htoi(line, len);

    printf("The value of %s is %u \n", (char *) line, value);

    return 0;
}

int mgetline(char line[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = (char) c;

    line[i] = '\0';

    return i;
}

unsigned int htoi(const char s[], int len) {
    int digit;
    int power = 1;
    unsigned int result = 0;
    int end_index = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        end_index = 2;
    }

    for(int i=len-1; i>=end_index; i--) {
        if (s[i] >= '0' && s[i] <= '9') {
            digit = (s[i] - '0');
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            digit = (s[i] - 'a') + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            digit = (s[i] - 'A') + 10;
        }
        result += digit * power;
        power *= BASE;
    }

    return result;
}