/***
 *
 * Exercise 2.1
 *
 * Program to print maximum, minimum limits of char, int, long using
 * calculation
 *
 ***/

/* The logic used is
 * ~0 will give bits in 1s.
 * (unsigned <type>) will cast it unsigned.
 * >> 1 right shifts 1 bit to remove the sign bit.
 * (<type>) casting it the required type again
 */

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
    /* ranges of various floating-point types through calculation */
    printf("Ranges of various floating-point types through calculation:\n");

    printf("Minimum Signed Char %d\n", -(char) ((unsigned char) ~0 >> 1) - 1);
    printf("Maximum Signed Char %d\n", (char) ((unsigned char) ~0 >> 1));

    printf("Minimum Signed Short %d\n", -(short) ((unsigned short) ~0 >> 1) - 1);
    printf("Maximum Signed Short %d\n", (short) ((unsigned short) ~0 >> 1));

    printf("Minimum Signed Int %d\n", -(int) ((unsigned int) ~0 >> 1) - 1);
    printf("Maximum Signed Int %d\n", (int) ((unsigned int) ~0 >> 1));

    printf("Minimum Signed Long %ld\n", -(long) ((unsigned long) ~0 >> 1) - 1);
    printf("Maximum signed Long %ld\n", (long) ((unsigned long) ~0 >> 1));

    /* Unsigned Maximum Values */

    printf("Maximum Unsigned Char %d\n", (unsigned char) ~0);
    printf("Maximum Unsigned Short %d\n", (unsigned short) ~0);
    printf("Maximum Unsigned Int %u\n", (unsigned int) ~0);
    printf("Maximum Unsigned Long %lu\n\n", (unsigned long) ~0);

    /* ranges of various floating-point types from standard headers */
    printf("Ranges of various floating-point types from standard headers:\n");
    printf("Minimum Signed Char %d\n", SCHAR_MIN);
    printf("Maximum Signed Char %d\n", SCHAR_MAX);

    printf("Minimum Signed Short %d\n", SHRT_MIN);
    printf("Maximum Signed Short %d\n", SHRT_MAX);

    printf("Minimum Signed Int %d\n", INT_MIN);
    printf("Maximum Signed Int %d\n", INT_MAX);

    printf("Minimum Signed Long %ld\n", LONG_MIN);
    printf("Maximum signed Long %ld\n", LONG_MAX);

    /* Unsigned Maximum Values */

    printf("Maximum Unsigned Char %d\n", UCHAR_MAX);
    printf("Maximum Unsigned Short %d\n", USHRT_MAX);
    printf("Maximum Unsigned Int %u\n", UINT_MAX);
    printf("Maximum Unsigned Long %lu\n", ULONG_MAX);

    return 0;
}
