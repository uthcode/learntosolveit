/* Concept: recursive string reverse using static index */
#include <stdio.h>
#include <string.h>
void reverse(char s[]) {
    static int i = 0;
    static int len;
    int j; char c;
    if (i == 0) len = strlen(s);
    j = len - (i + 1);
    if (i < j) {
        c = s[i]; s[i] = s[j]; s[j] = c;
        i++;
        reverse(s);
    } else i = 0;
}
int main(void) {
    char s[] = "hello";
    reverse(s);
    printf("%s\n", s);
    return 0;
}
