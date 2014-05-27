/* Write a function undef that will remove a name and definition
 * from the table maintained by lookup and install.
 */

#include<stdlib.h>
#include<stdio.h>

/* nlist from K&R Page 144 */

struct nlist { 				/* table entry: */
	struct nlist *next; 	/* next entry in chain */
	char *name;				/* defined name */
	char *defn;				/* replacement text */
};


#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];	/* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;

	for(hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;

	return hashval % HASHSIZE;
}


/* lookup: look for s in hashtab */

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;	/* found */
	return NULL;		/* not found */
}

struct nlist *lookup(char *);
char *strdup(char *);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL)  {	/* not found */
		np = (struct nlist *) malloc(sizeof(*np));

		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else 	/* already there */
		free((void *) np->defn);	/* free the previous defn */

	if ((np->defn = strdup(defn)) == NULL)
		return NULL;

	return np;
}


int main(int argc, char *argv[])
{
	struct nlist *n;

	n = install("key", "value");
	n = install("key1", "value1");

	for(; n !=NULL; n=n->next) {
		printf("%s->%s", n->name, n->defn);
	}

}
