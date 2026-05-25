/* Concept: RPN eval — push operands, pop and operate, print result */
#include <stdio.h>
int sp = 0;
double val[4];
void push(double v) { if (sp < 4) val[sp++] = v; }
double pop(void)    { return sp > 0 ? val[--sp] : 0.0; }
int main(void) {
    push(3.0); push(4.0);
    double op2 = pop();
    push(pop() + op2);
    printf("3 4 + = %.0f\n", pop());
    push(6.0); push(2.0);
    op2 = pop();
    push(pop() / op2);
    printf("6 2 / = %.0f\n", pop());
    return 0;
}
