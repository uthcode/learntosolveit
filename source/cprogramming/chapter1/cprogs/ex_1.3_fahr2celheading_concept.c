/* Concept: temperature table with header row */
#include <stdio.h>
int main(void) {
    float fahr, celsius;
    printf("Fahr\tCelsius\n");
    for (fahr = 0; fahr <= 40; fahr += 20) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%4.0f %10.1f\n", fahr, celsius);
    }
    return 0;
}
