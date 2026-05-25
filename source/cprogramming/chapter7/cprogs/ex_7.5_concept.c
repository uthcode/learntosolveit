/* Concept: RPN stack — push, pop, and apply arithmetic operator */
#include <stdio.h>
int sp = 0;
double val[4];
void push(double v) { if (sp < 4) val[sp++] = v; }
double pop(void)    { return sp > 0 ? val[--sp] : 0.0; }
int main(void) {
    double op2;
    push(5.0); push(3.0);
    op2 = pop(); push(pop() - op2);
    printf("5 3 - = %.0f\n", pop());
    push(2.0); push(4.0);
    push(pop() + pop());
    printf("2 4 + = %.0f\n", pop());
    return 0;
}
