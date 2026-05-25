/* Concept: RPN calculator with math function dispatch */
#include <math.h>
#include <stdio.h>
#define MAXVAL 10
int sp = 0;
double val[MAXVAL];
void push(double f) { if (sp < MAXVAL) val[sp++] = f; }
double pop(void) { return sp > 0 ? val[--sp] : 0.0; }
int main(void) {
    /* 2 3 + = 5, then sin(0) */
    push(2); push(3);
    push(pop() + pop());
    printf("%.8g\n", pop());
    printf("sin(0): %.4f\n", sin(0.0));
    return 0;
}
