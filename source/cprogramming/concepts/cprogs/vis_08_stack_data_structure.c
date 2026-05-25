/* Visualization: sp index advances/retreats in val[] — the LIFO stack in action */
#include <stdio.h>
int sp = 0;
double val[4];
void push(double v) { val[sp++] = v; }
double pop(void)    { return val[--sp]; }
int main(void) {
    push(1.0); push(2.0); push(3.0);
    printf("pop=%.0f\n", pop()); /* 3 */
    printf("pop=%.0f\n", pop()); /* 2 */
    push(9.0);
    printf("pop=%.0f\n", pop()); /* 9 */
    printf("pop=%.0f\n", pop()); /* 1 */
    return 0;
}
