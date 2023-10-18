#include<stdio.h>
#include<string.h>

#define MAXLINES 5000   /* max #lines to be sorted */

char *lineptr[MAXLINES];
char linestor[MAXLINES];

int readlines(char *lineptr[], char *linestor, int maxlines);

void writelines(char *lineptr[], int nlines);

void qsort(char *v[], int left, int right);

/* sort input lines */

int main(void) {
    int nlines; /* number of input lines read */

    if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort \n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
#define MAXSTOR 5000

int mgetline(char *, int);

char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], char *linestor, int maxlines) {
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines = 0;

    while ((len = mgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p + len > linestop)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */

void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define ALLOCSIZE 10000  /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

char *alloc(int n)  /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else
        return 0;
}

int mgetline(char *s, int lim) {
    int c;
    char *t = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;

    *s = '\0';

    return s - t;
}

