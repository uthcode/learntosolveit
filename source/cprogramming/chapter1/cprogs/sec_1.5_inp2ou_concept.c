/* Concept: copy characters from a string to output */
#include <stdio.h>
int main() {
    char s[] = "hi\n";
    int i = 0;
    while (s[i]) { putchar(s[i]); i++; }
}
