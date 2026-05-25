/* Concept: strindex scans s for first match of pattern t */
#include <stdio.h>
int strindex(char s[], char t[]) {
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++);
        if (k > 0 && t[k] == '\0') return i;
    }
    return -1;
}
int main(void) {
    printf("%d\n", strindex("hello", "ell")); /* 1 */
    printf("%d\n", strindex("hello", "xyz")); /* -1 */
    return 0;
}
