/* Concept: macro that swaps two values of any type using a temp variable */
#include <stdio.h>
#define swap(t, x, y) { t _z; _z = x; x = y; y = _z; }
int main(void) {
    char x = 'a', y = 'b';
    printf("before: x=%c y=%c\n", x, y);
    swap(char, x, y);
    printf("after:  x=%c y=%c\n", x, y);
    return 0;
}
