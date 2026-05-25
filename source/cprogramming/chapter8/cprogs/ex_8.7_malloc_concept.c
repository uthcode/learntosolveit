/* Concept: malloc uses a union header to ensure proper alignment */
#include <stdio.h>
typedef long Align;
union header {
    struct { union header *ptr; unsigned size; } s;
    Align x;
};
typedef union header Header;
int main(void) {
    printf("Header size: %zu bytes\n", sizeof(Header));
    printf("Align  size: %zu bytes\n", sizeof(Align));
    Header h;
    h.s.size = 4;
    h.s.ptr  = NULL;
    printf("Block size: %u\n", h.s.size);
    return 0;
}
