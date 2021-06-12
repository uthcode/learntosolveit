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

#define MAXWORD 1000

struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct bynumbernode
{
    int number;
    struct words *wordlist;
    struct bynumbernode *left;
    struct bynumbernode *right;
};

struct words
{
    char *word;
    struct words *nextword;
};

struct tnode *addtree(struct tnode *p, char *w);
struct bynumbernode *addnumtree(struct bynumbernode *, int, char*);
struct words *addwordtolist(struct words*, char *);
void printwords(const struct words*, const int);

struct bynumbernode *traverse(const struct tnode *, struct bynumbernode *);
void treeprint(const struct bynumbernode *);
int mgetword(char *, int);

struct tnode *talloc(void){
    return (struct tnode *)malloc(sizeof(struct tnode));
};

struct bynumbernode *bynumbernodealloc(void){
    return (struct bynumbernode *)malloc(sizeof(struct bynumbernode));
};

struct words *wordsalloc(void){
    return (struct words *)malloc(sizeof(struct words));
};



#define BUFSIZE 100

char buf[BUFSIZE];
int bufp=0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c){
    if(bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    }
    else buf[bufp++] = c;
    return;
}

char *mstrdup(char *s){
    char *p;
    p = (char *)malloc(strlen(s) + 1);
    if(p != NULL){
        strcpy(p, s);
    }
    return p;
}



int getword(char *word, int lim){
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch()) || c == '_' || c == '/' || c == '#' || c == '*' || c == '"');

    if(c != EOF){
        *w++ = c;
    }
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for( ; --lim > 0; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
/* addtree : add a node with w at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL){ /* new word */
        p = talloc(); // make new node
        p->word = mstrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0){
        p->count++;
    }
    else if(cond < 0){
        p->left = addtree(p->left, w);
    }
    else{
        p->right = addtree(p->right, w);
    }
    return p;
}
// treeprint: in-order print of tree p
void treeprint(const struct bynumbernode *p){
    if(p != NULL){
        treeprint(p->left);
        printwords(p->wordlist, p->number);
        treeprint(p->right);
    }
}

void printwords(const struct words* w, const int count)
{
    if (w != NULL){
        printf("%d->%s", count, w->word);
        w = w->nextword;
    }
    while (w != NULL) {
        printf(", %s",  w->word);
        w = w->nextword;
    }
    printf("\n");
}


struct words *addwordtolist(struct words* list, char *w){
    if(list == NULL){
        list = wordsalloc();
        list->word = mstrdup(w);
        list->nextword = NULL;
    }
    else {
        list->nextword = addwordtolist(list->nextword, w);
    }
    return list;
}


struct bynumbernode *addnumtree(struct bynumbernode *n, int i, char *w){
    if (n == NULL){
        n = bynumbernodealloc();
        n->number = i;
        n->wordlist = NULL;
        n->wordlist = addwordtolist(n->wordlist, w);
    }
    else if (n->number == i){
        addwordtolist(n->wordlist, w);
    }
    else if (n->number < i){
        n->left = addnumtree(n->left, i, w);
    }
    else{
        n->right = addnumtree(n->right, i, w);
    }
    return n;
}

struct bynumbernode *traverse(const struct tnode *p, struct bynumbernode *q){
    if(p != NULL){
        q = traverse(p->left, q);
        q = addnumtree(q, p->count, p->word);
        q = traverse(p->right, q);
    }
    return q;
}

void main(){
    struct tnode *root;
    char word[MAXWORD];
    
    struct bynumbernode *nroot;


    root = NULL;
    nroot = NULL;
    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0])){
            root = addtree(root, word);
        }
    }
    
    nroot = traverse(root, nroot);

    printf("Words by frequency:\n");
    
    treeprint(nroot);
    return;
}





