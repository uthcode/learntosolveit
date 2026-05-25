/* Concept: conditional expression to convert uppercase to lowercase */
#include <stdio.h>
int lower(int c) { return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c; }
int main(void) {
    char s[] = "Hi";
    int i = 0;
    while (s[i]) { putchar(lower(s[i])); i++; }
    putchar('\n');
}
