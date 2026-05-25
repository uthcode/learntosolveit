/* Concept: invert n bits of x starting at position p */
#include <stdio.h>
unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << (p + 1 - n));
}
int main(void) {
    printf("%u\n", invert(8u, 3, 3));  /* 1000 -> bits 3..1 flipped -> 0110 | rest = 6 */
    return 0;
}
