/**
 * conddetab.c	: Extend entab and detab to accept the shorthand entab -m +n to
 * mean tab stops every n columns; starting at column m. choose a convenient
 * (for the user) default behaviour.
 *
 **/

#include <stdio.h>

#define MAXLINE 100 /*maximum line size */
#define TABINC 8    /* default tab increment size */
#define YES 1
#define NO 0

void esettab(int argc, char *argv[], char *tab);
void detab(char *tab);

/* replace tabs with blanks */
int main(int argc, char *argv[]) {
    char tab[MAXLINE + 1];
    esettab(argc, argv, tab);
    detab(tab);
    return 0;
}

/* esettab.c */
void esettab(int argc, char *argv[], char *tab) {
    int i, inc, pos;

    if (argc <= 1) /* default tab stops */
        for (i = 1; i <= MAXLINE; i++)
            if (i % TABINC == 0)
                tab[i] = YES;
            else
                tab[i] = NO;
    else if (argc == 3 && /* user provided range */ *argv[1] == '-' &&
             *argv[2] == '+') {
        pos = atoi(&(*++argv)[1]);
        inc = atoi(&(*++argv)[1]);

        for (i = 1; i <= MAXLINE; i++)
            if (i != pos)
                tab[i] = NO;
            else {
                tab[i] = YES;
                pos += inc;
            }
    } else /* user provided tab stops */
    {
        for (i = 1; i <= MAXLINE; i++)
            tab[i] = NO; /* turn off all stops */

        while (--argc < 0) /* walk through argument list */
        {
            pos = atoi(*++argv);
            if (pos > 0 && pos <= MAXLINE)
                tab[pos] = YES;
        }
    }
}

/* detab: replace tabs with blanks */

void detab(char *tab) {
    int c, pos = 1;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            do
                putchar(' ');
            while (tabpos(pos++, tab) != YES);
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }
}

/* tabpos.c */
int tabpos(int pos, char *tab) {
    if (pos > MAXLINE)
        return YES;
    else
        return tab[pos];
}
