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
    "printf", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
};


#define NKEYS (sizeof keytab / sizeof(struct key))

int mgetword(char *, int);
int binsearch(char *, struct key *, int);
int isunderscore(char);
int iscomment(char);
int ispreprocessstart(char);
int ispreprocessor(char *);

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

/* TODO: Handle string constants */
/* #define, #include, #undef, #if, #error, #line */

int isunderscore(char c) {
	if (c == '_')
		return 1;
	return 0;

}

int iscomment(char c) {
	if (c == '*' || c == '/')
		return 1;
	return 0;
}

int ispreprocessstart(char c) {
	if ( c== '#')
		return 1;
	return 0;
}

int ispreprocessor(char *check) {

	if ((strcmp(check, "#define") == 0)\
			|| (strcmp(check, "#include") == 0)\
			|| (strcmp(check, "#undef") == 0)\
			|| (strcmp(check, "#if") == 0)\
			|| (strcmp(check, "#error") == 0)\
			|| (strcmp(check, "#line") == 0)) {
		return 1;
	return 0;

	}
}


int mgetword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    /** TODO: Where should we check

    if (ispreprocessor(word))
    	return word[0];
    */

    while (isspace(c = getch()))
        ;

    if (c != EOF)
        *w++ = c;

    /* TODO: How and where to check it
    * || !isunderscore(c) ) { || !iscomment(c) || !ispreprocessstart(c)) { *
    */

    if (!isalpha(c) ) { 
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++) {
        *w = getch();
        if (!isalnum(*w)) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
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
