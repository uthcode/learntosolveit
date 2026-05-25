/* Concept: static local variable retains value between function calls */
#include <stdio.h>
int counter(void) {
    static int count = 0;
    return ++count;
}
int main(void) {
    printf("%d\n", counter());
    printf("%d\n", counter());
    printf("%d\n", counter());
    return 0;
}
