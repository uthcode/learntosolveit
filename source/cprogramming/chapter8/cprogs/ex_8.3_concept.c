/* Concept: buffered I/O — getchar reads from a buffer, refills when empty */
#include <stdio.h>
int main(void) {
    char buf[] = "hi\n";
    int pos = 0, cnt = 3;
    while (cnt-- > 0) {
        int c = (unsigned char)buf[pos++];
        putchar(c);
    }
    return 0;
}
