/* Concept: RPN calculator with named variable storage */
#include <stdio.h>
#define MAXVAL 10
int sp = 0;
double val[MAXVAL];
double variable[26];
void push(double f) { if (sp < MAXVAL) val[sp++] = f; }
double pop(void) { return sp > 0 ? val[--sp] : 0.0; }
int main(void) {
    /* 5 -> A, then A 3 + = 8 */
    push(5);
    variable['A'-'A'] = pop();
    push(variable['A'-'A']);
    push(3);
    push(pop() + pop());
    printf("%.8g\n", pop());
    return 0;
}
