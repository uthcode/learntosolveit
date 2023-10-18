/**
 *
 * Exercise 1.15
 *
 * Temperature Conversion. Floating point, Symbolic Constant. Functions
 *
 **/

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void fahr_to_celsius(void);

void celsius_to_fahr(void);

int main(void) {
    int c;

    printf("Temperature Conversion Table\n");
    printf("1 - Fahrenheit to Celsius Conversion\n");
    printf("2 - Celsius to Fahrenheit Conversion\n");
    printf("- Enter your Choice\n");

    c = getchar();

    if (c == '1')
        fahr_to_celsius();
    else if (c == '2')
        celsius_to_fahr();
    else
        printf("Invalid Choice\n");

    return 0;
}

void fahr_to_celsius() {
    float fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3.0f%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
}

void celsius_to_fahr() {
    float celsius;

    for (celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP)
        printf("%3.0f%6.1f\n", celsius, (9.0 * celsius) / 5.0 + 32);
}
