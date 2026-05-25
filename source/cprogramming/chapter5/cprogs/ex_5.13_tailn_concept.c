/* Concept: circular buffer to keep last N lines */
#include <stdio.h>
#include <string.h>
#define TAIL 2
#define MAXLEN 10
int main(void) {
    char lines[TAIL][MAXLEN];
    char *data[] = {"line1", "line2", "line3"};
    int n = 3, i;
    for (i = 0; i < n; i++) strcpy(lines[i % TAIL], data[i]);
    for (i = 0; i < TAIL; i++) printf("%s\n", lines[(n + i) % TAIL]);
    return 0;
}
