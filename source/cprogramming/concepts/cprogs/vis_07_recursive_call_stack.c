/* Visualization: each recursive call pushes a new frame; base case unwinds them */
#include <stdio.h>
int fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}
int main(void) {
    printf("4! = %d\n", fact(4));
    return 0;
}
