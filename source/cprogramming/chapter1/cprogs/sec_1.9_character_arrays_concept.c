/* Concept: find longest of two strings using copy function */
#include <stdio.h>
void copy(char to[], char from[]);
int main() {
    char s1[] = "hi", s2[] = "hello", longest[10];
    int len1 = 2, len2 = 5;
    if (len1 > len2) copy(longest, s1);
    else copy(longest, s2);
    printf("%s\n", longest);
    return 0;
}
void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}
