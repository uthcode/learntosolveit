/* Concept: pointer array into shared storage; swap pointers to sort */
#include <stdio.h>
#include <string.h>
int main(void) {
    char store[14] = "banana\0apple";
    char *lines[2];
    lines[0] = store;
    lines[1] = store + 7;
    if (strcmp(lines[0], lines[1]) > 0) {
        char *tmp = lines[0]; lines[0] = lines[1]; lines[1] = tmp;
    }
    printf("%s\n%s\n", lines[0], lines[1]);
    return 0;
}
