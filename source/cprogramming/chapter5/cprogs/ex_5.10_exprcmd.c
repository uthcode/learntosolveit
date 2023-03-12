/**
 *
 * Write a program exprcmd, which evaluates a reverse polish expression, from
 * the command line,where each operator or operand is a seperate argument. For
 * eg: expr  2 3 4 + * evaluates to 2 * ( 3 + 4)
 *
 **/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100  /* maximum size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define BUFSIZE 100
#define MAXVAL 100 /* maximum depth of value of stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */
char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getop(char[]);
void ungets(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* reverse polish calculator, uses command line */

int main(int argc, char *argv[]) {
    char s[MAXOP];
    double op2;

    while (--argc > 0) {
        ungets(" "); /* push end of argument */
        ungets(*++argv);

        switch (getop(s)) {
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
                printf("error: zero divisor \n");
            break;
        default:
            printf("error: unknown command %s \n", s);
            argc = 1;
            break;
        }
    }
    printf("\t %8g\n", pop());

    return 0;
}

/* getop: get next operator or numeric operand */

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    i = 0;

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect from fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';

    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] = c;
}

/* push : push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g \n", f);
}

/* pop: pop and return top value from the stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty \n");
        return 0.0;
    }
}

/* ungets: push string back onto the input */
void ungets(char s[]) {
    int len = strlen(s);
    void ungetch(int);

    while (len > 0)
        ungetch(s[--len]);
}
