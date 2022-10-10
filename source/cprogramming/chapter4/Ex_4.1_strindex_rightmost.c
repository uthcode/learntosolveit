/**
 * Exercise 4.1 - The C Programming Language
 *
 * Write the function strindex(s,t) which returns the position of the rightmost
 * occurrence of t in s, or -1 if there is none.
 *
 */

#include <stdio.h>

int mstrindex(char s[], char t[]);

int main(int argc, char *argv[]) {
    char line[] = "abcdedfabcde";
    char pattern[] = "abc";

    int found;

    found = mstrindex(line, pattern);
    printf("Found: %d\n", found);
}

int mstrindex(char s[], char t[]) {
    int i, j, k, result;

    result = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            result = i;
    }
    return result;
}
