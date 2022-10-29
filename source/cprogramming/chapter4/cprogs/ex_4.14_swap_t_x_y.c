/**
 * Exercise 4.14 of The C Programming Language by Brian Kernighan and Dennis
 * Ritchie
 *
 * Write a macro swap(t,x,y) that interchanges two arguments of type t. (Block
 * structure will help.)
 *
 */

#include <stdio.h>

#define swap(t, x, y)                                                          \
    {                                                                          \
        t temp;                                                                \
        temp = x;                                                              \
        x = y;                                                                 \
        y = temp;                                                              \
    }

int main() {
    int x = 1;
    int y = 2;
    printf("x = %d, y = %d\n", x, y);
    swap(int, x, y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
