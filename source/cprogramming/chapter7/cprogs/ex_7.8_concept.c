/* Concept: line and page counters control file pagination */
#include <stdio.h>
#define LINESPERPAGE 3
int main(void) {
    char *lines[] = {"line1","line2","line3","line4","line5"};
    int i, line = 0, pg = 1;
    for (i = 0; i < 5; i++) {
        printf("%s\n", lines[i]);
        if (++line == LINESPERPAGE) {
            printf("--- Page %d end ---\n", pg++);
            line = 0;
        }
    }
    return 0;
}
