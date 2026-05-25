/* Visualization: static n lives in global frame across calls; local would reset */
#include <stdio.h>
int counter(void) {
    static int n = 0;  /* persists between calls */
    n++;
    return n;
}
int main(void) {
    printf("%d\n", counter()); /* 1 */
    printf("%d\n", counter()); /* 2 */
    printf("%d\n", counter()); /* 3 */
    return 0;
}
