/* Concept: while loop temperature conversion, 3 iterations */
#include <stdio.h>
int main() {
    int fahr = 0, celsius;
    while (fahr <= 40) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + 20;
    }
    return 0;
}
