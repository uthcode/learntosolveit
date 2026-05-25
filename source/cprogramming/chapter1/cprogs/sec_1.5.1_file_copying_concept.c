/* Concept: file copying with for loop */
#include <stdio.h>
int main() {
    char s[] = "hi\n";
    int i;
    for (i = 0; s[i]; i++) putchar(s[i]);
}
