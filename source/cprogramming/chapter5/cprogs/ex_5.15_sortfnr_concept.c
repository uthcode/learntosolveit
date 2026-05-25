/* Concept: sort using a function pointer for comparison strategy */
#include <stdio.h>
#include <string.h>
int cmpforward(char **a, char **b) { return strcmp(*a, *b); }
int cmpbackward(char **a, char **b) { return strcmp(*b, *a); }
int main(void) {
    char *lines[3] = {"banana", "apple", "cherry"};
    int (*cmp)(char **, char **) = cmpforward;
    int i, j;
    char *tmp;
    for (i = 0; i < 2; i++)
        for (j = i+1; j < 3; j++)
            if (cmp(&lines[i], &lines[j]) > 0) { tmp = lines[i]; lines[i] = lines[j]; lines[j] = tmp; }
    for (i = 0; i < 3; i++) printf("%s\n", lines[i]);
    return 0;
}
