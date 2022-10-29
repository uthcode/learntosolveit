/**
 * Exercise 4.13 of The C Programming Language by Brian Kernighan and Dennis Ritchie
 *
 * Write a recursive version of the function reverse(s), which reverses the string s in place.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[], int i, int j);

int main(void)
{
    char s[MAXLINE];
    int i, j;

    printf("Enter a string: ");
    fgets(s, MAXLINE, stdin);
    i = 0;
    j = strlen(s) - 1;
    reverse(s, i, j);
    printf("Reversed string: %s\n", s);
    return 0;
}

void reverse(char s[], int i, int j)
{
    int c;

    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverse(s, ++i, --j);
    }
}


