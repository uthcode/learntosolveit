/* Concept: buffered getchar keeps a static buf+ptr+n; drains without re-reading */
#include <stdio.h>
int main(void) {
    /* simulate bgetchar state: static buffer filled once by read() */
    char buf[8] = "hi\n";
    char *bufp = buf;
    int n = 3;
    printf("buffer: \"%s\"  n=%d\n", buf, n);
    while (n-- > 0) {
        int c = (unsigned char)*bufp++;
        putchar(c);
    }
    printf("n=%d (buffer empty)\n", n);
    return 0;
}
