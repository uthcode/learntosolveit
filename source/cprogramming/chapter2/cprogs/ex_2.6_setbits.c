/**
 *
 * Exercise 2.6 -  Write a function setbits(x,p,n,y) that returns x with the
 * n bits that begin at position p set to the rightmost n bits of y,leaving
 * the other bits unchanged.
 **/

#include <assert.h>
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return x & ((~0 << p + 1) | ~(~0 << p + 1 - n)) | ((y & ~(~0 << n)) << p + 1 - n);
}


int main(void) {

    printf("%u", setbits((unsigned)12, 3, 2, (unsigned)57));

    assert(setbits(0x2, 2, 2, 0xD) == 0x2);    /* x=00000(01)0  y=000011(01) : equal to x */
    assert(setbits(0x2, 0, 0, 0xD) == 0x2);    /* x=00000010    y=00001101   : equal to x */
    assert(setbits(0xF, 3, 1, 0xE) == 0x7);    /* x=0000(1)111  y=0000111(0) : 0000(0)111 */
    assert(setbits(0x37, 3, 2, 0x4E) == 0x3B); /* x=0011(01)11  y=010011(10) : 0011(10)11 */
    assert(setbits(0x37, 7, 8, 0x4E) == 0x4E); /* x=(00110111)  y=(01001110) : equal to y */
    assert(setbits(0xFF, 3, 4, 0x00) == 0xF0); /* x=1111(1111)  y=0000(0000) : 1111(0000) */
    assert(setbits(0xFF, 0, 1, 0x00) == 0xFE); /* x=1111111(1)  y=0000000(0) : 1111111(0) */

    return 0;
}