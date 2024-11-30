/**
 * Add a field handling capability, so sorting may be done on the fields within lines,
 * each field sorted according to an independent set of options.
 * The index for the KnR Book was sorted with -df for the index category and -n for page number
 **/

#include<stdio.h>
#include<ctype.h>

#define NUMERIC  1    /* numeric sort */
#define DECR    2    /* sort in decreasing order */
#define    FOLD    4    /* fold upper and lower case */
#define MDIR    8    /* directory order */
#define LINES    100    /* maximum number of lines to be sorted */

int charcmp(char *, char *);

void error(char *);

int numcmp(char *, char *);

void readargs(int argc, char *argv[]);

int readlines(char *lineptr[], int maxlines);

void myqsort(void *v[], int left, int right, int (*comp)(void *, void *));

void writelines(char *lineptr[], int nlines, int order);

int option = 0;

int pos1 = 0;    /* field begining with pos 1 */
int pos2 = 0;    /* ending just before pos 2 */


/* Sort input line */

int main(int argc, char *argv[]) {
    char *lineptr[LINES];    /* pointer to text lines */
    int nlines;        /* number of input lines read */
    int rc = 0;

    readargs(argc, argv);

    if ((nlines = readlines(lineptr, LINES)) > 0) {
        if (option & NUMERIC)
            myqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) numcmp);
        else
            myqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) charcmp);

        writelines(lineptr, nlines, option & DECR);
    } else {
        printf("input too big to sort \n");
        rc = -1;
    }

    return rc;
}

/* readargs: read programs argument */

void readargs(int argc, char *argv[]) {
    int c;
    int atoi(char *);

    while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+') {
        if (c == '-' && !isdigit(*(argv[0] + 1)))
            while (c = *++argv[0])
                switch (c) {
                    case 'd':    /* directory order */
                        option |= MDIR;
                        break;
                    case 'f':
                        /* fold upper and lower */
                        option |= FOLD;
                        break;
                    case 'n':
                        /* numeric sort */
                        option |= NUMERIC;
                        break;
                    case 'r':
                        option |= DECR;
                        break;
                    default:
                        printf("sort: illegal option %c \n", c);
                        error("Usage: sort -dfnr [+pos1] [-pos2]");
                        break;
                }
        else if (c == '-')
            pos2 = atoi(argv[0] + 1);
        else if ((pos1 = atoi(argv[0] + 1)) < 0)
            error("Usage: sort -dfnr [+pos1][-pos2]");
    }

    if (argc || pos1 > pos2)
        error("Usage: sort -dfnr [+pos1] [-pos2]");
}

/* The source file numcmp.c */

#include<math.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>

#define MAXSTR 100

void substr(char *s, char *t, int maxstr);

/* numcmp: compare s1 and s2 numerically */

int numcmp(char *s1, char *s2) {
    double v1, v2;
    char str[MAXSTR];

    substr(s1, str, MAXSTR);
    v1 = atof(str);

    substr(s2, str, MAXSTR);
    v2 = atof(str);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

#define FOLD    4    /* fold upper and lower cases */
#define MDIR    8    /* directory order */

/* charcmp: return < 0 if s < t, 0 if s =t, >0 if s > t */
int charcmp(char *s, char *t) {
    char a, b;
    int i, j, endpos;

    extern int option, pos1, pos2;
    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & MDIR) ? 1 : 0;

    i = j = pos1;

    if (pos2 > 0)
        endpos = pos2;
    else if ((endpos = strlen(s)) > strlen(t))
        endpos = strlen(t);

    do {
        if (dir) {
            while (i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0')
                s[i] != ' ' && s[i] != '\0';
            i++;
            while (j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
                t[j] != ' ' && t[j] != '\0';
            j++;
        }
        if (i < endpos && j < endpos) {
            a = fold ? tolower(s[i]) : s[i];
            i++;
            b = fold ? tolower(t[j]) : t[j];
            j++;

            if (a == b && a == '\0')
                return 0;
        }
    } while (a == b && i < endpos && j < endpos);

    return a - b;
}

/* The source file substr.c */

#include<string.h>

void error(char *);

/* substr: get a substring of S and put in str */

void substr(char *s, char *str, int maxstr) {
    int i, j, len;
    extern int pos1, pos2;

    len = strlen(s);

    if (pos2 > 0 && len > pos2)
        len = pos2;
    else if (pos2 > 0 && len < pos2)
        error("substr: string too short");
    for (j = 0, i = pos1; i < len; i++, j++)
        str[j] = str[i];
    str[j] = '\0';
}

/* error: print error message and exit */

void error(char *s) {
    printf("%s \n", s);
    exit(1);
}


void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* myqsort: sort v[left] ... v[right] into increasing order */

void myqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)        /* do nothing if array contains */
        return;

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);

    myqsort(v, left, last - 1, comp);
    myqsort(v, last + 1, right, comp);
}


#define MAXLEN    1000        /* max length of any input line  */

int mgetline(char *, int);

char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';    /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int order) {
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}


#define ALLOCSIZE 10000            /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;        /* next free position */

char *alloc(int n)            /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;    /* old p */
    } else                /* not enough room */
        return 0;
}

void afree(char *p)        /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}


/* mgetline: read a line into s,return length */

int mgetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
			
