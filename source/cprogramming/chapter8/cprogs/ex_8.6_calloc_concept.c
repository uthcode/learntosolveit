/* Concept: calloc allocates n*size bytes and zeros them */
#include <stdio.h>
#include <stdlib.h>
void *mycalloc(unsigned n, unsigned size) {
    unsigned i, nb = n * size;
    char *p, *q;
    if ((p = q = malloc(nb)) != NULL)
        for (i = 0; i < nb; i++) *p++ = 0;
    return q;
}
int main(void) {
    int *arr = mycalloc(3, sizeof(int));
    if (arr) {
        printf("%d %d %d\n", arr[0], arr[1], arr[2]);
        free(arr);
    }
    return 0;
}
