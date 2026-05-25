/* Concept: reverse order temperature table */
#include <stdio.h>
int main(void) {
    float celsius;
    printf("C     F\n\n");
    for (celsius = 40; celsius >= 0; celsius -= 20)
        printf("%3.0f %6.1f\n", celsius, (9.0/5.0)*celsius + 32.0);
    return 0;
}
