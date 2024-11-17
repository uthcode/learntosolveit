 /*
 * Write a cross-referencer that prints a list of all words in a document,
 * and for each word, a list of the line numbers on which it occurs.
 * Remove noise words like "the" and "and" so on.
 *
 */

/*
 * 1. Create a binary tree that will contain words and structure with lines on which words occur.
 * 2. Check if the word is noisy with binary search.
 * 3. Print the words and lines.
 * */

#define N_OF_NOISEWORDS 123

const char *noiseWords[N_OF_NOISEWORDS]={"a", "about", "after", "all",
"also", "an", "another", "any", "are", "as", "and", "at", "be",
"because", "been", "before", "being", "between", "but", "both",
"by", "came", "can", "come", "could","did", "do","each", "even",
"for", "from", "further", "furthermore","get", "got","has", "had",
"he", "have", "her", "here", "him", "himself", "his", "how", "hi",
"however","i", "if", "in", "into", "is", "it", "its", "indeed","just",
"like","made", "many", "me", "might", "more", "moreover", "most", 
"much","must", "my","never", "not", "now","of", "on", "only", "other",
"our", "out", "or", "over","said", "same", "see", "should", "since",
"she", "some", "still", "such","take", "than", "that", "the", "their",
"them", "then", "there", "these", "therefore", "they", "this", "those",
"through", "to", "too", "thus","under", "up","very","was", "way", "we",
"well", "were", "what", "when", "where", "which", "while", "who",
"will", "with", "would","you", "your"};

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 500

int binarySearch(const char *arr[], int l, int r, char *x);

void treeprint(const struct tnode *p);
char *mstrdup(char *s);

int getWord(char *word, int lim);

void ungetch(char c);
int getch(void);

char buf;  /* buffer for getch/ungetch */

struct tnode *talloc(void);
struct tnode *addtree(struct tnode *p, char *w, unsigned int l);

void printline(const struct ocurLine *p);

struct ocurLine *linealloc(void);
struct ocurLine *addLine(struct ocurLine *p, unsigned int l);

struct tnode{
	char *word;
	unsigned int count;
    struct ocurLine *lineOfOccurence;

	struct tnode *left;
	struct tnode *right;
};

struct ocurLine{
    unsigned int line;
    struct ocurLine *next;
};


int main()
{
	int l=1;
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	
	while(getWord(word, MAXWORD) != EOF)
		if (word[0] == '\n') // Adding 1 to [l] if there is new line
			l++;
		else if(isalpha(word[0]))
			if (binarySearch(noiseWords, 0, N_OF_NOISEWORDS, word) == -1)
				root = addtree(root, word, l);
	treeprint(root);
}


 /* Binary search for our array of noise words. */
int binarySearch(const char *arr[], int l, int r, char *x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2;
 		int cmp = strcmp(arr[mid], x);

        if (cmp == 0)
            return mid; 

        if (cmp > 0) 
            return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return -1; 
}


int getWord(char *word, int lim)
{
    int c;

    char *w = word;

    while (isspace(c = getch()) && c != '\n')
        ;

    if (c != EOF)
        *w++ = c;

    if (!isalpha(c) && c != '_' && c != '#') {
        *w = '\0';
        return c;
    }

    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }

    *w = '\0';
    return word[0];
}

/* addtree: adds branch to a tree*/
struct tnode *addtree(struct tnode *p, char *w, unsigned int l)
{
    int cond;

    if(p == NULL) { /* new word */
        p = talloc();
        p->word=mstrdup(w);
        p->count = 1;
        p->lineOfOccurence = NULL;
        p->lineOfOccurence = addLine(p->lineOfOccurence, l);
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->word)) == 0){
    	p->count++;
        p->lineOfOccurence = addLine(p->lineOfOccurence, l);
    }
    else if(cond < 0)
        p->left = addtree(p->left, w, l);
    else
        p->right = addtree(p->right, w, l);
    return p;
}

/* treeprint: prints all the branches of the tree with words.*/
void treeprint(const struct tnode *p)
{

    if(p != NULL) {
        treeprint(p->left);

        printf("%s: [", p->word);

        printline(p->lineOfOccurence);

    	printf("]\n");

        treeprint(p->right);
    }
}

/* talloc: From K&R2 page 142. Makes a tnode. */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}


/* printline: Prints all lines.*/
void printline(const struct ocurLine *p)
{
    if (p->next == NULL)
        printf("%i", p->line);
    else{
        printf("%i, ", p->line);
        printline(p->next);
    }
}

/* addLine: adds a line to word. */
struct ocurLine *addLine(struct ocurLine *p, unsigned int l)
{
    if (p == NULL){
        p = linealloc();
        p->line = l;
        p->next = NULL;
    }
    else
        p->next = addLine(p->next, l);
    return p;
}

/* linealloc: Makes ocurLine*/
struct ocurLine *linealloc(void)
{
    return (struct ocurLine *) malloc(sizeof(struct ocurLine));
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

/*************************************************************
 *      Getch/Ungetch functions from previous exercises      *
 *************************************************************/

/* getch: gets a (possibly pushed-back) character */
int getch(void)
{
    if (buf > 0){
        int copy=buf;
        buf=0;
        return copy;
    }
    else
        return getchar();
}

/* ungetch: pushes character back on input */
void ungetch(char c)
{
    buf = c;
}
