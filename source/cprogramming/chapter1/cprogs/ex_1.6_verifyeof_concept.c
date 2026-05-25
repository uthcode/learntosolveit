/* Concept: EOF is -1, comparison with != yields 0 or 1 */
#include <stdio.h>
int main(void) {
    printf("EOF value: %d\n", EOF);
    printf("'a' != EOF: %d\n", 'a' != EOF);
    printf("EOF != EOF: %d\n", EOF != EOF);
    return 0;
}
