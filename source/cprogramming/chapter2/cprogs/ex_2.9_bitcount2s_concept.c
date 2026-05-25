/* Concept: x &= (x-1) clears rightmost 1-bit in two's complement */
#include <stdio.h>
int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= x - 1) ++b;
    return b;
}
int main(void) {
    printf("%d\n", bitcount(12u));  /* 12 = 1100 -> 2 set bits */
    printf("%d\n", bitcount(7u));   /* 7  = 0111 -> 3 set bits */
    return 0;
}
