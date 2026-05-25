/* Concept: binary tree that counts word occurrences */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tnode { char *word; int count; struct tnode *left, *right; };
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;
    if (!p) {
        p = malloc(sizeof(struct tnode));
        p->word = strdup(w); p->count = 1; p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) < 0) p->left  = addtree(p->left,  w);
    else if (cond > 0)                          p->right = addtree(p->right, w);
    else                                        p->count++;
    return p;
}
void treeprint(struct tnode *p) {
    if (p) { treeprint(p->left); printf("%4d %s\n", p->count, p->word); treeprint(p->right); }
}
int main(void) {
    struct tnode *root = NULL;
    char *words[] = {"int", "char", "int"};
    int i;
    for (i = 0; i < 3; i++) root = addtree(root, words[i]);
    treeprint(root);
    return 0;
}
