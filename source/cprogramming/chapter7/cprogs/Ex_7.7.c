/*
 * Modify the pattern finding program of Chapter 5 to take its input from a set
 * of named files or, if no files are named as arguments, from the standard
 * input. Should the file name be printed when a matching line is found?
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int mgetline(char *line, int max);

char pattern[] = "ould"; /* pattern to search for */

/* find all the matching patterns */

int main(void) {
    char line[MAXLINE];

    int found = 0;

    /* mgetline ends when a newline starts with X */
    while ((mgetline(line, MAXLINE)) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s\n", line);
            found++;
        }

    return 0;
}

/* mgetline */

int mgetline(char *s, int lim) {
    int c;
    char *t = s;

    while (--lim > 0 && (c = getchar()) != 'X' && c != '\n')
        *s++ = c;

    if (c == '\n')
        *s++ = c;
    *s = '\0';

    return s - t;
}

/* strindex */

int strindex(char *s, char *t) {
    char *b = s;
    char *p, *r;

    for (; *s != '\0'; s++) {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
            ;

        if (r > t && *r == '\0')
            return s - b;
    }
    return -1;
}
