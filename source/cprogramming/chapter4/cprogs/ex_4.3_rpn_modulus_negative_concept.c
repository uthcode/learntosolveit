/* Concept: RPN stack — push operands, apply operator, pop result */
#include <stdio.h>
#define MAXVAL 10
int sp = 0;
double val[MAXVAL];
void push(double f) { if (sp < MAXVAL) val[sp++] = f; }
double pop(void) { return sp > 0 ? val[--sp] : 0.0; }
int main(void) {
    /* 10 2 % = 0 */
    push(10); push(2);
    int remainder = (int)pop();
    printf("%d\n", (int)pop() % remainder);
    return 0;
}
