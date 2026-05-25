/* Concept: sort with -d (directory order: only letters/digits) option */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int charcmp(char *s1, char *s2, int fold, int dir) {
    while (*s1 && *s2) {
        if (dir && !isalnum(*s1)) { s1++; continue; }
        if (dir && !isalnum(*s2)) { s2++; continue; }
        int c1 = fold ? tolower(*s1) : *s1;
        int c2 = fold ? tolower(*s2) : *s2;
        if (c1 != c2) return c1 - c2;
        s1++; s2++;
    }
    return *s1 - *s2;
}
int main(void) {
    char *lines[3] = {"Banana", "apple", "Cherry"};
    int i, j;
    char *tmp;
    for (i = 0; i < 2; i++)
        for (j = i+1; j < 3; j++)
            if (charcmp(lines[i], lines[j], 1, 0) > 0) { tmp = lines[i]; lines[i] = lines[j]; lines[j] = tmp; }
    for (i = 0; i < 3; i++) printf("%s\n", lines[i]);
    return 0;
}
