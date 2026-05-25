/* Concept: pointer walks to end of s, then copies t char-by-char */
#include <stdio.h>
void mystrcat(char *s, char *t) {
    while (*s) s++;
    while ((*s++ = *t++) != '\0');
}
int main(void) {
    char s[10] = "hi";
    mystrcat(s, "!!");
    printf("%s\n", s);
    return 0;
}
