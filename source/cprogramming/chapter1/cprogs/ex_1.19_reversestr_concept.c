/* Concept: reverse a string in-place using two pointers */
#include <stdio.h>
int main(void) {
    char s[] = "hello";
    int i = 0, j, len;
    char temp;
    while (s[i]) i++;
    len = i;
    for (i = 0, j = len-1; i < j; i++, j--) {
        temp = s[i]; s[i] = s[j]; s[j] = temp;
    }
    printf("%s\n", s);
    return 0;
}
