/* Concept: hash table — install name/definition pairs and look them up */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 7
struct nlist { struct nlist *next; char *name; char *defn; };
static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *s) {
    unsigned hv;
    for (hv = 0; *s; s++) hv = *s + 31 * hv;
    return hv % HASHSIZE;
}
struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np; np = np->next)
        if (strcmp(s, np->name) == 0) return np;
    return NULL;
}
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    if ((np = lookup(name)) == NULL) {
        np = malloc(sizeof(*np));
        np->name = strdup(name); np->next = NULL;
        hashtab[hash(name)] = np;
    } else free(np->defn);
    np->defn = strdup(defn);
    return np;
}
int main(void) {
    install("PI", "3.14159");
    install("E",  "2.71828");
    struct nlist *p;
    p = lookup("PI"); if (p) printf("%s = %s\n", p->name, p->defn);
    p = lookup("E");  if (p) printf("%s = %s\n", p->name, p->defn);
    return 0;
}
