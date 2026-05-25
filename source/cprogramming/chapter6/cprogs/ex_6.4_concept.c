/* Concept: word-frequency BST — each node stores word + count */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct wnode { char word[8]; int count; struct wnode *l, *r; };
struct wnode *add(struct wnode *p, char *w) {
    int c;
    if (!p) {
        p = malloc(sizeof *p);
        strncpy(p->word, w, 7); p->word[7] = 0;
        p->count = 1; p->l = p->r = NULL;
    } else if ((c = strcmp(w, p->word)) == 0) p->count++;
    else if (c < 0) p->l = add(p->l, w);
    else            p->r = add(p->r, w);
    return p;
}
void print(struct wnode *p) {
    if (!p) return;
    print(p->l);
    printf("%d %s\n", p->count, p->word);
    print(p->r);
}
int main(void) {
    struct wnode *root = NULL;
    char *words[] = {"hi","bye","hi","ok","bye","hi"};
    int i;
    for (i = 0; i < 6; i++) root = add(root, words[i]);
    print(root);
    return 0;
}
