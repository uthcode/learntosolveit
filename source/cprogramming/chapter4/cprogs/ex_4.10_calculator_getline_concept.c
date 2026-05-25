/* Concept: RPN using getline buffer instead of getch/ungetch */
#include <stdio.h>
#define MAXVAL 10
int sp = 0;
double val[MAXVAL];
void push(double f) { if (sp < MAXVAL) val[sp++] = f; }
double pop(void) { return sp > 0 ? val[--sp] : 0.0; }
int main(void) {
    /* 2 3 + = 5 */
    push(2); push(3);
    push(pop() + pop());
    printf("%.8g\n", pop());
    return 0;
}
