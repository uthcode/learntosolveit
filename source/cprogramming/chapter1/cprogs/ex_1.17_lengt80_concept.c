/* Concept: print only strings longer than a limit */
#include <stdio.h>
int main(void) {
    char *lines[2] = {"hi", "hello"};
    int limit = 4, i, len;
    for (i = 0; i < 2; ++i) {
        len = 0;
        while (lines[i][len]) len++;
        if (len > limit) printf("%s\n", lines[i]);
    }
    return 0;
}
