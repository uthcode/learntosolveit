/**
 * Exercise 2.1
 *
 * Write a program to print maximum, minimum limits of char, int, long using
 * calculation.
 *
 */

/**
 * Priminary Information:
 *
 * ~0 will give bits in 1s.
 * >> 1 right shift by 1 bit to remove the sign bit.
 * -1 is added to the maximum limit to get the minimum limit.
 *
 * The maximum and minimum limits of various integer types can be calculated
 * using the following logic:
 *
 * 1. The maximum limit of a signed integer type can be calculated by
 *   (unsigned <type>) ~0 >> 1
 *
 * 2. The minimum limit of a signed integer type can be calculated by
 *  ((unsigned <type>) ~0 >> 1) - 1
 *   *
 * 3. We cast it back to the required type with sign to print the value.
 *
 */

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
    /* ranges of various integer types through calculation */
    printf("Ranges of various floating-point types through calculation:\n");

    printf("Minimum Signed Char %d\n", -(char)((unsigned char)~0 >> 1) - 1);
    printf("Maximum Signed Char %d\n", (char)((unsigned char)~0 >> 1));

    printf("Minimum Signed Short %d\n", -(short)((unsigned short)~0 >> 1) - 1);
    printf("Maximum Signed Short %d\n", (short)((unsigned short)~0 >> 1));

    printf("Minimum Signed Int %d\n", -(int)((unsigned int)~0 >> 1) - 1);
    printf("Maximum Signed Int %d\n", (int)((unsigned int)~0 >> 1));

    printf("Minimum Signed Long %ld\n", -(long)((unsigned long)~0 >> 1) - 1);
    printf("Maximum signed Long %ld\n", (long)((unsigned long)~0 >> 1));

    /* Unsigned Maximum Values */

    printf("Maximum Unsigned Char %d\n", (unsigned char)~0);
    printf("Maximum Unsigned Short %d\n", (unsigned short)~0);
    printf("Maximum Unsigned Int %u\n", (unsigned int)~0);
    printf("Maximum Unsigned Long %lu\n\n", (unsigned long)~0);

    /* Calculating max values of float types can be tricky, we can use the standard headers */

    /* ranges of various floating-point types from standard headers */
    printf("Ranges of various integer and floating-point types from standard headers:\n");
    printf("Minimum Signed Char %d\n", SCHAR_MIN);
    printf("Maximum Signed Char %d\n", SCHAR_MAX);

    printf("Minimum Signed Short %d\n", SHRT_MIN);
    printf("Maximum Signed Short %d\n", SHRT_MAX);

    printf("Minimum Signed Int %d\n", INT_MIN);
    printf("Maximum Signed Int %d\n", INT_MAX);

    printf("Minimum Signed Long %ld\n", LONG_MIN);
    printf("Maximum signed Long %ld\n", LONG_MAX);

    printf("Minimum Signed Long Long %lld\n", LLONG_MIN);
    printf("Maximum signed Long Long %lld\n", LLONG_MAX);

    printf("Minimum Float %E\n", FLT_MIN);
    printf("Maximum Float %E\n", FLT_MAX);

    printf("Minimum Double %E\n", DBL_MIN);
    printf("Maximum Double %E\n", DBL_MAX);

    printf("Minimum Long Double %LE\n", LDBL_MIN);
    printf("Maximum Long Double %LE\n", LDBL_MAX);

    /* Unsigned Maximum Values */

    printf("Maximum Unsigned Char %d\n", UCHAR_MAX);
    printf("Maximum Unsigned Short %d\n", USHRT_MAX);
    printf("Maximum Unsigned Int %u\n", UINT_MAX);
    printf("Maximum Unsigned Long %lu\n", ULONG_MAX);
    printf("Maximum Unsigned Long Long %llu\n", ULLONG_MAX);

    return 0;
}