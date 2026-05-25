/* Concept: compute alignment padding to align a block to long boundary */
#include <stdio.h>
typedef long Align;
#define ALIGN_PAD(p) ((sizeof(Align) - ((unsigned)(long)(p) % sizeof(Align))) % sizeof(Align))
int main(void) {
    char buf[20];
    int i;
    for (i = 0; i <= 3; i++) {
        char *p = buf + i;
        unsigned pad = ALIGN_PAD(p);
        printf("offset=%d, pad=%u, aligned_offset=%d\n", i, pad, i + (int)pad);
    }
    return 0;
}
