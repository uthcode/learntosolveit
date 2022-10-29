/**
 * Exercise 4.4 - The C Programming Language by Dennis M. Ritchie and Brian W.
 * Kernighan
 *
 * Add commands to print the top elements of the stack without popping, to
 * duplicate it, and to swap the top two elements.
 * Add a command to clear the stack.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

/* Reverse Polish calculator */

int main(int argc, char *argv[]) {
    int type;
    double op2;
    char s[MAXOP];

    while (--argc > 0) {
        type = getop(*++argv);
        switch (type) {
        case NUMBER:
            push(atof(*argv));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;

        case 'p':
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'd':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':
            op2 = pop();
            double op3 = pop();
            push(op2);
            push(op3);
            break;
        case 'c':
            while (pop() != 0.0)
                ;
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", *argv);
            break;
        }
    }
    return 0;
}
