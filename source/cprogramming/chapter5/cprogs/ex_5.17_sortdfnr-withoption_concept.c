/* Concept: sort with combined -d -f -n -r options via flag variables */
#include <stdio.h>
#include <string.h>
int main(void) {
    char *lines[3] = {"banana", "apple", "cherry"};
    int reverse = 1;  /* -r flag: sort descending */
    int i, j;
    char *tmp;
    for (i = 0; i < 2; i++)
        for (j = i+1; j < 3; j++) {
            int cmp = strcmp(lines[i], lines[j]);
            if (reverse) cmp = -cmp;
            if (cmp > 0) { tmp = lines[i]; lines[i] = lines[j]; lines[j] = tmp; }
        }
    for (i = 0; i < 3; i++) printf("%s\n", lines[i]);
    return 0;
}
