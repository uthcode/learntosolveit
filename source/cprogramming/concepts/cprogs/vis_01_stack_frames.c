/* Visualization: each function call creates a new stack frame with its own locals */
#include <stdio.h>
int add(int a, int b) { return a + b; }
int mul(int x, int y) { return x * y; }
int main(void) {
    int p = add(2, 3);  /* new frame for add: a=2, b=3 */
    int q = mul(p, 4);  /* new frame for mul: x=5, y=4 */
    printf("%d\n", q);
    return 0;
}
