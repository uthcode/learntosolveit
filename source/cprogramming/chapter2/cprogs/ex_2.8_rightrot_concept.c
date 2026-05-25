/* Concept: rotate integer x right by n bit positions */
#include <stdio.h>
unsigned rightrot(unsigned x, int n) {
    int wordlength = 32;
    unsigned rbit = x << (wordlength - n);
    x = x >> n;
    return x | rbit;
}
int main(void) {
    printf("%u\n", rightrot(8u, 1));  /* 1000 rotated right 1 = 0100 = 4 */
    printf("%u\n", rightrot(1u, 1));  /* 0001 rotated right 1 = MSB set */
    return 0;
}
