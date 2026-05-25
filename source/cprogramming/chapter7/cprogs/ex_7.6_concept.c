/* Concept: compare two sequences line-by-line, report first difference */
#include <stdio.h>
#include <string.h>
int main(void) {
    char *file1[] = {"hello", "world", NULL};
    char *file2[] = {"hello", "there", NULL};
    int i = 0;
    while (file1[i] && file2[i]) {
        if (strcmp(file1[i], file2[i]) != 0) {
            printf("First diff: '%s' vs '%s'\n", file1[i], file2[i]);
            break;
        }
        i++;
    }
    return 0;
}
