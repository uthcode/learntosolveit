#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key {
    char *word;
    int count;
} keytab[] =  {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
    "printf", 0, /* Figure out why printf is a special case */
};


#define NKEYS (sizeof keytab / sizeof(struct key))

int mgetword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */
int main(int argc, char *argv[])
{
    int n;
    char word[MAXWORD];

    while (mgetword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
            for (n = 0; n < NKEYS; n++)
                if (keytab[n].count > 0)
                    printf("%4d %s\n", keytab[n].count, keytab[n].word);
                return 0;

}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;

}

/* getword: get next word or character from input */

/* The requirement is to skip underscore, comments and pre-processor directive */
#define IN 1
#define OUT 0



int mgetword(char *word, int lim)
{
    int c, d, getch(void), comment, string, directive;
    void ungetch(int);
    char *w = word;

    comment = string = directive = OUT;

    while (isspace(c = getch()))
        ;

    /* Check if inside a comment */

    if (c == '/') {
        if ((d = getch()) == '*') {
            comment = IN;
        } else {
            comment = OUT;
            ungetch(d);
        }
    }

    /* Check if inside a quote */

    if ( c == '\"') {
        string = IN;
    }

    /* Check if inside a directive */

    if (c == '#') {
            directive = IN;
    }

    if ( c == '\\') {
        c = getch(); /* ignore the \\ character */
    }

    if (comment == OUT && string == OUT && directive == OUT) {

        if (c != EOF)
            *w++ = c;

        if (!isalnum(c) && c !='_' ) {
            *w = '\0';
            return c;
        }

        for ( ; --lim > 0; w++) {
            *w = getch();
            if (!isalnum(*w) && *w != '_') {
                ungetch(*w);
                break;
            }
        }
        *w = '\0';
        return word[0];
    }
    else if ( comment == IN) {
        *w++ = c;
        *w++ = d;

        while ((*w++ = c = getch())) {
            if ( c == '*' ) {
                if ( (c = getch()) == '/' ) {
                    *w++ = c;
                    comment = OUT;
                    break;
                } else {
                    ungetch(c);
                }
            }
        }
        *w = '\0';

    }
    else if ( string == IN) {
        *w++ = c;
        while ((*w++ = getch()) != '\"') {
            if ( *w == '\\')  /* Take care of escaped quotes */
                *w++ = getch();
        }
        string = OUT;
        *w = '\0';
    }
    else if (directive == IN) {
        *w++ = c;
        while ((*w++ = getch()) != '\n') {
            if ( c == '\\') { /* Take care of continuation line escape */
                *w++ = getch();
            }
        }
        directive = OUT;
        *w = '\0';
    }

    return c;

}

#define BUFSIZE  100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void)     /* get a (possibly pushed back) character */
{
    return ( bufp > 0)? buf[--bufp] : getchar();
}

void ungetch(int c)     /* push a character back on input */
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters \n");
    else
        buf[bufp++] = c;
}
