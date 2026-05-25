/* Concept: function dispatch for temperature conversion */
#include <stdio.h>
#define LOWER 0
#define UPPER 40
#define STEP 20
void fahr_to_celsius(void);
int main(void) {
    printf("Fahrenheit to Celsius:\n");
    fahr_to_celsius();
    return 0;
}
void fahr_to_celsius() {
    float fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3.0f %6.1f\n", fahr, (5.0/9.0)*(fahr-32.0));
}
