#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100
#define MAXWORD 1000
#define IN 1
#define OUT 0
#define HASHSIZE 101


char buf[BUFSIZE]; /* buffer for ungetch() */
int bufp = 0;      /* next free position in buf */

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* linked list. nlist from K&R Page 144 */
struct nlist {          /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};


int getch(void) { /* get a (possibly pushed back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
    return;
}

/* hash: form hash value for string s */
unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;

    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; /* found */
    return NULL;       /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *)malloc(sizeof(*np));

        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else                      /* already there */
        free((void *)np->defn); /* free the previous defn */

    if ((np->defn = strdup(defn)) == NULL)
        return NULL;

    return np;
}

struct nlist *undef(char *name) {
    struct nlist *found;

    found = lookup(name);

    if (found == NULL) /* not found and nothing to do */
        return NULL;
    else {
        if (found->next != NULL) {
            found->next = found->next->next;
            found = found->next;
        } else {
            hashtab[hash(name)] = NULL;
            free((void *)found);
        }
    }
    return found;
}

int mgetword(char *word, int lim, int *lineno_addr) {
    int c, d, getch(void), comment, string, directive;
    void ungetch(int);
    char *w = word;

    comment = string = directive = OUT;

    while (isspace(c = getch())) {
        if (c == '\n') {

            *lineno_addr = *lineno_addr + 1;
        }
    }
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
    if (c == '\"') {
        string = IN;
    }

    /* Check if inside a directive */
    if (c == '#') {
        directive = IN;
    }

    if (c == '\\') {
        c = getch(); /* ignore the \\ character */
    }

    if (comment == OUT && string == OUT && directive == OUT) {

        if (c != EOF)
            *w++ = c;

        if (!isalnum(c) && c != '_') {
            *w = '\0';
            return c;
        }

        for (; --lim > 0; w++) {
            *w = getch();
            if (!isalnum(*w) && *w != '_') {
                ungetch(*w);
                break;
            }
        }
        *w = '\0';
        return word[0];
    } else if (comment == IN) {
        *w++ = c;
        *w++ = d;

        while ((*w++ = c = getch())) {
            if (c == '*') {
                if ((c = getch()) == '/') {
                    *w++ = c;
                    comment = OUT;
                    break;
                } else {
                    ungetch(c);
                }
            }
        }
        *w = '\0';

    } else if (string == IN) {
        *w++ = c;
        while ((*w++ = getch()) != '\"') {
            if (*w == '\\') /* Take care of escaped quotes */
                *w++ = getch();
        }
        string = OUT;
        *w = '\0';
    } else if (directive == IN) {
        *w++ = c;
        while ((*w++ = getch()) != ' ') {
            if (c == '\\') { /* Take care of continuation line escape */
                *w++ = getch();
            }
        }

        directive = OUT;
        *w = '\0';
    }

    return c;
}

int main(void) {

    int lineno = 0;
    char word[MAXWORD];

    char key[MAXWORD], value[MAXWORD];

    struct nlist *result;

    while (mgetword(word, MAXWORD, &lineno) != 'x') {
        if (strcmp(word, "#define ") == 0) {
            mgetword(key, MAXWORD, &lineno);
            mgetword(value, MAXWORD, &lineno);
            install(key, value);
            result = lookup(key);
            printf("%s->%s", result->name, result->defn);
        }
    }

    return 0;
}