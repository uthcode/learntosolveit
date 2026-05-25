/* Concept: find rightmost occurrence of pattern in string */
#include <stdio.h>
int mstrindex(char s[], char t[]) {
    int i, j, k, result = -1;
    for (i = 0; s[i]; i++) {
        for (j = i, k = 0; t[k] && s[j] == t[k]; j++, k++);
        if (k > 0 && t[k] == '\0') result = i;
    }
    return result;
}
int main(void) {
    char line[] = "abcabc";
    char pattern[] = "abc";
    printf("Found at index: %d\n", mstrindex(line, pattern));  /* 3 */
    return 0;
}
