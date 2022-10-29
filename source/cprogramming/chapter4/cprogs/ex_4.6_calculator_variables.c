/**
 *
 * Exercise 4.6 of The C Programming Language by Brian Kernighan and Dennis
 * Ritchie.
 *
 * Add commands for handling variables. (It's easy to provide twenty-six
 * variables with single-letter names.)
 *
 * Add a variable for the most recently printed value.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

int main(int argc, char *argv[]) {
    int type;
    int var = 0;

    double op2;
    double v = 0.0;
    double variable[26];

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
                push((int)pop() % (int)op2);
            else
                printf("error: zero divisor\n");
            break;
        case '=':
            pop();
            if (var >= 'A' && var <= 'Z')
                variable[var - 'A'] = pop();
            else
                printf("error: no variable name\n");
            break;
        case 'v':
            push(v);
            break;
        case 'V':
            v = pop();
            push(v);
            break;
        case 's':
            op2 = pop();
            push(pop());
            push(op2);
            break;
        case 'c':
            while (pop() != 0.0)
                ;
            break;
        case 'd':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 'p':
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        default:
            if (type >= 'A' && type <= 'Z')
                push(variable[type - 'A']);
            else if (type == 'v')
                push(v);
            else
                printf("error: unknown command %s\n", *argv);
            break;
        }
        var = type;
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
