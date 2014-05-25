/*
 * Write a program that prints the distinct words in its input sorted into
 * decreasing order of frequency of occurrence. Precede each word by its count.
 */

/*
 * Create a Tree with word and count, just like tnode.
 * Parse the tree and create a new tree with count and list of words in the node.
 * Print the new tree in-order traversal.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#define MAXWORD 1000     /* longest word that can be read by mgetword */

/*
 * tnode: Tree node from K&R2 page 140.  Words are initially read into
 * the tree by getword.
 */
struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct numwordnode
{
	int number;
	struct words *wordslist;
	struct numwordnode *left;
	struct numwordnode *right;
};

struct words
{
	char *word;
	struct words *nextword;
};

struct tnode *addtree(struct tnode *, char *);
struct numwordnode *addnumtree(struct numwordnode *, int, char*);
struct words *addwordtolist(struct words*, char *);
void printwords(const struct words*);

void traverse(const struct tnode *, struct numwordnode *);
void treeprint(const struct numwordnode *);
int mgetword(char *, int);

int main(int argc, char *argv[])
{
    struct tnode *root;
    struct numwordnode *numwordroot;

    char word[MAXWORD];

    /* get all the words */
    root = NULL;
    numwordroot = NULL;

    while(mgetword(word, MAXWORD) != 'x')
        if(isalpha(word[0]))
            root = addtree(root, word);

    traverse(root, numwordroot);

    treeprint(numwordroot);

    return 0;
}

struct tnode *talloc(void);
struct numwordnode *numwordalloc(void);
struct words *wordsalloc(void);
char *mstrdup(char *);

/* mgetword from Ex6.1 */

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



/***************************************************************************
 *                    All code below here is from K&R2.                    *
 ***************************************************************************/

/*
 * addtree: From K&R2 page 141.
 * Adds a node containing w, at or below node p.
 */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if(p == NULL) { /* new word */
        p = talloc();
        p->word = mstrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if(cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

struct numwordnode *addnumtree(struct numwordnode *p, int count, char* w)
{
	if (p == NULL) {
		p = numwordalloc();
		p->number = count;
		p->wordslist = NULL;
		p->wordslist = addwordtolist(p->wordslist, w);
	}
	else if (count < p->number)
		p->left = addnumtree(p->left, count, w);
	else
		p->right = addnumtree(p->right, count, w);
	return p;
}

struct words *addwordtolist(struct words* list, char *w)
{
	if (list == NULL) {
		list = wordsalloc();
		list->word = mstrdup(w);
		list->nextword = NULL;
	} else {
		list->nextword = addwordtolist(list->nextword, w);
	}
	return list;
}

/* treeprint: From K&R2 page 142. Prints tree p in-order. */
void treeprint(const struct numwordnode *p)
{
    if(p != NULL) {
        treeprint(p->left);
        printf("Count: %4d\n", p->number);
        printwords(p->wordslist);
        treeprint(p->right);
    }
}

void printwords(const struct words* w)
{
	if (w != NULL) {
		printf("%s,", w->word);
		w = w->nextword;
	}
}

void traverse(const struct tnode *p, struct numwordnode *q)
{

	if (p != NULL) {
		traverse(p->left, q);
		printf("%s->%d\n", p->word,p->count);
		q = addnumtree(q, p->count, p->word);
		traverse(p->right, q);
	}
}

/* talloc: From K&R2 page 142. Makes a tnode. */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

struct numwordnode *numwordalloc(void)
{
	return (struct numwordnode *) malloc(sizeof(struct numwordnode));
}

struct words *wordsalloc(void) {
	return (struct words *) malloc(sizeof(struct words));
}


/* strdup: From K&R2 page 143. Makes a duplicate of s. */
char *mstrdup(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if(p != NULL)
        strcpy(p, s);
    return p;
}

/*
 * getch and ungetch are from K&R2, page 79
 */
#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch() */
int bufp = 0;       /* next free position in buf */

int getch(void) { /* get a (possibly pushed back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {  /* push character back on input */
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
    return;
}