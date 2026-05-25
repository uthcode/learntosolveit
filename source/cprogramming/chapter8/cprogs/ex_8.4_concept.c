/* Concept: fseek must flush/discard buffer — cnt reset to 0, ptr reset to base */
#include <stdio.h>
int main(void) {
    char base[8] = "abcdefg";
    char *ptr = base + 3; /* 3 chars already consumed */
    int cnt = 4;           /* 4 chars remaining in buffer */
    printf("before seek: cnt=%d ptr_offset=%d\n", cnt, (int)(ptr - base));
    /* fseek: discard buffered read data */
    cnt = 0;
    ptr = base;
    printf("after seek:  cnt=%d ptr_offset=%d\n", cnt, (int)(ptr - base));
    return 0;
}
