/* Concept: hash table install/lookup for #define name->defn mapping */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 7
struct nlist { char name[8]; char defn[8]; struct nlist *next; };
static struct nlist *tab[HASHSIZE];
unsigned hash(char *s) {
    unsigned h = 0;
    while (*s) h = (unsigned)*s++ + 31 * h;
    return h % HASHSIZE;
}
void install(char *name, char *defn) {
    unsigned h = hash(name);
    struct nlist *np = malloc(sizeof *np);
    strncpy(np->name, name, 7); np->name[7] = 0;
    strncpy(np->defn, defn, 7); np->defn[7] = 0;
    np->next = tab[h]; tab[h] = np;
}
char *lookup(char *name) {
    struct nlist *np;
    for (np = tab[hash(name)]; np; np = np->next)
        if (!strcmp(name, np->name)) return np->defn;
    return NULL;
}
int main(void) {
    install("MAX", "100"); install("MIN", "0");
    char *r;
    r = lookup("MAX"); printf("MAX=%s\n", r ? r : "undef");
    r = lookup("MIN"); printf("MIN=%s\n", r ? r : "undef");
    r = lookup("X");   printf("X=%s\n",   r ? r : "undef");
    return 0;
}
