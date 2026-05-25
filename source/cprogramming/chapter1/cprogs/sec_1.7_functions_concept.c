/* Concept: defining and calling a function */
#include <stdio.h>
int power(int base, int n);
int main() {
    printf("%d %d %d\n", 0, power(2,0), power(-3,0));
    printf("%d %d %d\n", 1, power(2,1), power(-3,1));
    printf("%d %d %d\n", 2, power(2,2), power(-3,2));
    return 0;
}
int power(int base, int n) {
    int i, p = 1;
    for (i = 1; i <= n; ++i) p = p * base;
    return p;
}
