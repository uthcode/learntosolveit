/**
 * Exercise 4.10 of The C Programming Language by Brian Kernighan and Dennis
 * Ritchie
 *
 * An alternate organization uses getline to read an entire input line; this
 * makes getch and ungetch unnecessary. Revise the calculator to use this
 * approach.
 */

#include <stdio.h>
#include <stdlib.h> // for atof()

#define MAXOP 100  // max size of operand or operator
#define NUMBER '0' // signal that a number was found

int getop(char[]);
void push(double);
double pop(void);

/* reverse Polish calculator */

int main(int argc, char *argv[]) {
    int type;
    double op2;
    char s[MAXOP];

    while (--argc > 0) {
        type = getop(*++argv);
        switch (type) {
        case NUMBER:
            push(atof(s));
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
                push((int)pop() % (int)op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\0':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100 // maximum depth of val stack

int sp = 0; // next free stack position

double val[MAXVAL]; // value stack

/* push: push f onto value stack */

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* using getline instead of getch and ungetch */

#include <ctype.h>
#define MAXLINE 100

int mgetline(char line[], int limit);

int li = 0;         // index of next char in line
char line[MAXLINE]; // current input line

int getop(char s[]) {
    int i, c;

    if (line[li] == '\0') {

        if (mgetline(line, MAXLINE) == 0) {
            return '\0';
        }

        else {
            li = 0;
        }
    }

    while ((s[0] = c = line[li++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; // not a number
    i = 0;
    if (isdigit(c)) // collect integer part
        while (isdigit(s[++i] = c = line[li++]))
            ;
    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    li--;
    return NUMBER;
}

int mgetline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
