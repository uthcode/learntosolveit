/* Concept: pattern search — print lines containing the pattern */
#include <stdio.h>
#include <string.h>
int strindex(char *s, char *t) {
    char *b = s, *p, *r;
    for (; *s; s++) {
        for (p = s, r = t; *r && *p == *r; p++, r++);
        if (r > t && !*r) return s - b;
    }
    return -1;
}
int main(void) {
    char *lines[] = {"would you like it", "solve it now", NULL};
    char *pattern = "ould";
    int i;
    for (i = 0; lines[i]; i++)
        if (strindex(lines[i], pattern) >= 0) printf("%s\n", lines[i]);
    return 0;
}
