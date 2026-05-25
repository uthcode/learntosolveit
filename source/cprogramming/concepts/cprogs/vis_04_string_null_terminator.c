/* Visualization: a string is a char array ending with '\0' (value 0) */
#include <stdio.h>
int main(void) {
    char s[] = "hi!";
    int i = 0;
    while (s[i]) {
        printf("s[%d] = '%c'  (%d)\n", i, s[i], (int)s[i]);
        i++;
    }
    printf("s[%d] = '\\0' (%d)  <- null terminator\n", i, (int)s[i]);
    return 0;
}
