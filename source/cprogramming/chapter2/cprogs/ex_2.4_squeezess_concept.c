/* Concept: delete from s1 every character that appears in s2 */
#include <stdio.h>
int main(void) {
    char s1[] = "hello";
    char s2[] = "l";
    int i, j, k = 0;
    for (i = 0; s1[i]; i++) {
        for (j = 0; s1[i] != s2[j] && s2[j]; j++);
        if (!s2[j]) s1[k++] = s1[i];
    }
    s1[k] = '\0';
    printf("%s\n", s1);
    return 0;
}
