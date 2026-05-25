/* Concept: isupper as macro (inline) vs function — same logic, different dispatch */
#include <stdio.h>
#define ISUPPER(c) ((c) >= 'A' && (c) <= 'Z')
int myisupper(int c) { return c >= 'A' && c <= 'Z'; }
int main(void) {
    char s[] = "aAzZ";
    int i;
    for (i = 0; s[i]; i++)
        printf("'%c': macro=%d fn=%d\n", s[i], ISUPPER((unsigned char)s[i]),
               myisupper((unsigned char)s[i]));
    return 0;
}
