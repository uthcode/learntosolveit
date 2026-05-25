/* Concept: count characters with while loop */
#include <stdio.h>
int main() {
    char s[] = "hi\n";
    long nc = 0;
    int i = 0;
    while (s[i++]) ++nc;
    printf("%ld\n", nc);
}
