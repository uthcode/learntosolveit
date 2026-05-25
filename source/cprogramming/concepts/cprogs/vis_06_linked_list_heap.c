/* Visualization: malloc creates heap boxes; next pointers chain them */
#include <stdio.h>
#include <stdlib.h>
struct node { int val; struct node *next; };
int main(void) {
    struct node *a = malloc(sizeof *a); a->val = 1; a->next = NULL;
    struct node *b = malloc(sizeof *b); b->val = 2; b->next = NULL;
    struct node *c = malloc(sizeof *c); c->val = 3; c->next = NULL;
    a->next = b;
    b->next = c;
    struct node *p = a;
    while (p) { printf("%d\n", p->val); p = p->next; }
    return 0;
}
