/*
 * Exercise 6-2 in K&R2 on page 143.  Original By: Barrett Drawdy
 * Write a program that reads a C program and prints in alphabetical
 * order each group of variable names that are identical in the first
 * 6 characters, but different somewhere thereafter.  Don't count words
 * within strings and comments.  Make 6 a parameter that can be set
 * from the command line.
 */

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 1000       /* longest word that can be read by getword */
#define DEFAULT_COMP_LEN 6 /* default length to compare */

/*
 * tnode: Tree node from K&R2 page 140.  Words are initially read into
 * the tree by getword.
 */
struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

/*
 * simroot: Part of a linked list of pointers to simword lists with
 * a common root.
 */
struct simroot {
    struct simword *firstword; /* points to the list of words */
    struct simroot *nextroot;  /* points to the next node in the list */
};

/*
 * simword: Part of a linked list of words with a common root.  Points
 * to the word in the tnodes.
 */
struct simword {
    char *word;               /* points to the word in the tree */
    int count;                /* copied from the tree */
    struct simword *nextword; /* next node */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(const struct tnode *);
int mgetword(char *, int);
struct simroot *addroot(struct simroot *, struct tnode *, int);
struct simroot *parse(struct tnode *, int);
void printlist(struct simroot *, int);
void printwords(struct simword *);

int main(int argc, char *argv[]) {
    struct tnode *root;
    char word[MAXWORD];
    struct simroot *listroot;
    int len;

    /* get all the words */
    root = NULL;
    while (mgetword(word, MAXWORD) != 'x')
        if (isalpha(word[0]))
            root = addtree(root, word);

    if (argc == 1)
        len = DEFAULT_COMP_LEN;
    else if (argc == 2)
        len = atoi(argv[1]);
    else {
        printf("Incorrect number of arguments.\n");
        return 1;
    }

    /* parse the tree to find similar words and populate list */
    listroot = NULL;
    listroot = parse(root, len);
    treeprint(root); /* prints all the words */
    printf("\nDuplicate list:\n\n");
    printlist(listroot, len); /* prints the similar words */

    return 0;
} /* end of main() */

/*
 * parse: Reads the tree created by getword.  It finds words that are
 * similar in the first len letters and places them in the list structure
 * that it creates.
 */
struct simroot *parse(struct tnode *node, int len) {
    struct tnode *temp; /* pointer to the children of the node */
    int this_len;       /* length of the word in the current node */
    static struct simroot *root = NULL; /* points to the root of the tree */

    if (node == NULL)
        return NULL;

    this_len = strlen(node->word);

    parse(node->left, len); /* start in the left subtree */

    temp = node->left; /* find the closest left child and compare */
    if (temp != NULL) {
        while (temp->right != NULL)
            temp = temp->right;
        /* if the word matches, put both words in the list */
        if (this_len >= len && strncmp(temp->word, node->word, len) == 0) {
            root = addroot(root, temp, len);
            addroot(root, node, len);
        }
    }

    temp = node->right; /* find the closest right child and compare */
    if (temp != NULL) {
        while (temp->left != NULL)
            temp = temp->left;
        /* if the word matches, put both words in the list */
        if (this_len >= len && strncmp(temp->word, node->word, len) == 0) {
            root = addroot(root, node, len);
            addroot(root, temp, len);
        }
    }

    parse(node->right, len); /* continue on to right subtree */

    return root;
}

/*
 * printlist: Prints the roots that were similar, followed by the list
 * of words.
 */
void printlist(struct simroot *p, int len) {
    int i;
    if (p == NULL)
        return;
    for (i = 0; i < len; ++i) /* print the root */
        putchar(p->firstword->word[i]);
    putchar('\n');
    printwords(p->firstword);    /* print the list of words */
    printlist(p->nextroot, len); /* print the next root/list */
}

/*
 * printword: Prints the list of words with the same roots.
 */
void printwords(struct simword *p) {
    printf("  %4d %s\n", p->count, p->word);
    if (p->nextword != NULL)
        printwords(p->nextword);
}

struct tnode *talloc(void);
char *mstrdup(char *);
struct simword *walloc(struct simword *, struct tnode *);
void addword(struct simword *, struct tnode *);

/*
 * addroot: When a node n is passed to addroot, n->word is compared to the
 * first word in ps list.  If they have are the same for the first 'len'
 * characters, then the word is added to that list.  Otherwise, it is passed
 * along the simroots until it reaches the end, where a new simroot is
 * created if the word has a new root.
 */
struct simroot *addroot(struct simroot *p, struct tnode *n, int len) {
    /* end of list, create a new root */
    if (p == NULL) {
        p = (struct simroot *)malloc(sizeof(struct simroot));
        p->nextroot = NULL;
        p->firstword = walloc(p->firstword, n);
    }
    /* word belongs to this list, add it */
    else if (strncmp(p->firstword->word, n->word, len) == 0)
        addword(p->firstword, n);
    /* haven't found the right root or end yet */
    else
        p->nextroot = addroot(p->nextroot, n, len);
    return p;
}

/*
 * addword: Compares the word from n to the word in p.  If they are the same,
 * the word was already added and it returns.  This continues down the list
 * until the end, where a new node is created if the word is new.
 */
void addword(struct simword *p, struct tnode *n) {
    /* word was already added */
    if (strcmp(p->word, n->word) == 0)
        return;
    /* end of list. create a new node */
    if (p->nextword == NULL)
        p->nextword = walloc(p->nextword, n);
    /* haven't reached the end yet */
    else
        addword(p->nextword, n);
}

/* walloc: Creates a new simword node. */
struct simword *walloc(struct simword *p, struct tnode *n) {
    p = (struct simword *)malloc(sizeof(struct simword));
    if (p != NULL) {
        p->word = n->word;
        p->count = n->count;
        p->nextword = NULL;
    }
    return p;
}

/* mgetword from Ex6.1 */

#define IN 1
#define OUT 0

int mgetword(char *word, int lim) {
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
        while ((*w++ = getch()) != '\n') {
            if (c == '\\') { /* Take care of continuation line escape */
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
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) { /* new word */
        p = talloc();
        p->word = mstrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint: From K&R2 page 142. Prints tree p in-order. */
void treeprint(const struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc: From K&R2 page 142. Makes a tnode. */
struct tnode *talloc(void) {
    return (struct tnode *)malloc(sizeof(struct tnode));
}

/* strdup: From K&R2 page 143. Makes a duplicate of s. */
char *mstrdup(char *s) {
    char *p;
    p = (char *)malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

/*
 * getch and ungetch are from K&R2, page 79
 */
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch() */
int bufp = 0;      /* next free position in buf */

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
