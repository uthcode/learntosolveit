/* Concept: compute integer limits using bit tricks */
#include <stdio.h>
int main() {
    printf("Max Signed Char: %d\n", (int)((unsigned char)~0 >> 1));
    printf("Min Signed Char: %d\n", -(int)((unsigned char)~0 >> 1) - 1);
    printf("Max Signed Int: %d\n", (int)((unsigned int)~0 >> 1));
    return 0;
}
