/* Concept: count keyword occurrences using struct array + binary search */
#include <string.h>
#include <stdio.h>
struct key { char *word; int count; } keytab[] = {
    {"for", 0}, {"if", 0}, {"while", 0}
};
#define NKEYS 3
int binsearch(char *word) {
    int cond, low = 0, high = NKEYS - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, keytab[mid].word)) < 0) high = mid - 1;
        else if (cond > 0) low = mid + 1;
        else return mid;
    }
    return -1;
}
int main(void) {
    char *words[] = {"if", "for", "if", "while"};
    int i, n;
    for (i = 0; i < 4; i++)
        if ((n = binsearch(words[i])) >= 0) keytab[n].count++;
    for (i = 0; i < NKEYS; i++)
        if (keytab[i].count > 0) printf("%4d %s\n", keytab[i].count, keytab[i].word);
    return 0;
}
