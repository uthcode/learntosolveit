/* Concept: strncpy copies at most n chars, zero-pads if source is shorter */
#include <stdio.h>
void mystrncpy(char *t, char *s, int n) {
    for (; n > 0 && (*t = *s) != '\0'; t++, s++, n--);
    while (n-- > 0) *t++ = '\0';
}
int main(void) {
    char dst[10];
    mystrncpy(dst, "hello", 3);
    dst[3] = '\0';
    printf("%s\n", dst);  /* hel */
    return 0;
}
