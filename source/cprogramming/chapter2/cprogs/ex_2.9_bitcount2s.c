/* In twos complement number systems, x &= (x-1) deletes the rightmost 1 bit in
 * x. Explain why? Use this to right a faster version of bitcount. Bitcount
 * program counts the number of 1 bits in the integer */

#include <stdio.h>

int bitcount(unsigned x);

int main(void) { printf("%d", bitcount((unsigned) 12)); }

int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= x - 1)
        ++b;

    return b;
}
