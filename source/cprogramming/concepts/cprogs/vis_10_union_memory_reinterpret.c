/* Visualization: union fields share the same bytes — write int, read as chars */
#include <stdio.h>
union u { int i; char bytes[4]; };
int main(void) {
    union u x;
    x.i = 0x41424344;   /* stores 'D','C','B','A' in bytes (little-endian) */
    printf("as int:  0x%08X\n", (unsigned)x.i);
    int j;
    for (j = 0; j < 4; j++)
        printf("bytes[%d] = 0x%02X  '%c'\n", j,
               (unsigned char)x.bytes[j], x.bytes[j]);
    return 0;
}
