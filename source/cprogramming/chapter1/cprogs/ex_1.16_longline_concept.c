/* Concept: find and report the longest of two strings */
#include <stdio.h>
void copy(char to[], const char from[]);
int main() {
    char *lines[2] = {"hi", "hello"};
    char longest[10];
    int max = 0, i, len;
    for (i = 0; i < 2; ++i) {
        len = 0;
        while (lines[i][len]) len++;
        if (len > max) { max = len; copy(longest, lines[i]); }
    }
    printf("length = %d, string=%s\n", max, longest);
    return 0;
}
void copy(char to[], const char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}
