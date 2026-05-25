/* Concept: replace n bits of x starting at p with rightmost n bits of y */
#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return x & ((~0 << p + 1) | ~(~0 << p + 1 - n)) | ((y & ~(~0 << n)) << p + 1 - n);
}
int main(void) {
    printf("%u\n", setbits(0xF, 3, 1, 0xE));   /* 1111 -> 0111 = 7 */
    printf("%u\n", setbits(0xFF, 3, 4, 0x00));  /* 11111111 -> 11110000 = 240 */
    return 0;
}
