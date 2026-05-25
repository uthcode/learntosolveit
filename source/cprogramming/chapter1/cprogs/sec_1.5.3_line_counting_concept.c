/* Concept: count newlines in a string */
#include <stdio.h>
int main() {
    char s[] = "a\nb\n";
    int nl = 0, i = 0;
    while (s[i]) { if (s[i] == '\n') ++nl; i++; }
    printf("%d\n", nl);
}
