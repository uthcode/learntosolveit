/* Exercise 1-22: Write a program to "fold" long input lines into two or more
                  shorter lines after the last non-blank character that occurs
                  before the n-th column of input. */

#include <stdio.h>

#define MAXCOL 35                           /* folded line length */
#define TABVAL 8                            /* standard tab length */
#define CURTAB(c) (TABVAL - ((c) % TABVAL)) /* current tab size */
#define NO_BLANK -1                         /* signifies no blank found */

int lastblank(const char arr[], int len);

/* folds long input lines into two or more shorter lines */
int main(void) {
    int c;                 /* character variable */
    int i, j;              /* indexing variable(s) */
    int pos;               /* current position in array */
    int col;               /* current column of output */
    int lbc;               /* last blank character position */
    char line[MAXCOL + 1]; /* fold array */

    pos = col = 0;
    while ((c = getchar()) != EOF) {
        /* process line array, keep track of line length by columns */
        line[pos++] = c;
        col += (c == '\t') ? CURTAB(col) : 1;

        /* create fold */
        if (col >= MAXCOL || c == '\n') {
            line[pos] = '\0';

            if ((lbc = lastblank(line, pos)) == NO_BLANK) {
                /* split word if no blank characters */
                for (i = 0; i < pos; ++i)
                    putchar(line[i]);
                /* reset column value and array position */
                col = pos = 0;
            } else {
                /* print array up until last blank character */
                for (i = 0; i < lbc; ++i)
                    putchar(line[i]);
                /* feed remaining characters into buffer */
                for (i = 0, j = lbc + 1, col = 0; j < pos; ++i, ++j) {
                    line[i] = line[j];
                    /* set new column value */
                    col += (c == '\t') ? CURTAB(col) : 1;
                }
                /* set array position after remaining characters */
                pos = i;
            }
            /* finish folded line with newline character */
            putchar('\n');
        }
    }

    return 0;
}

/* finds the last whitespace character in an array
   and returns the position */
int lastblank(const char arr[], int len) {
    int i, lbc;

    lbc = -1;
    for (i = 0; i < len; ++i)
        if (arr[i] == ' ' || arr[i] == '\t' || arr[i] == '\n')
            lbc = i;

    return lbc;
}
