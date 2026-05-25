/* Concept: return first position in s1 where any s2 character appears */
#include <stdio.h>
int main(void) {
    char s1[] = "hello";
    char s2[] = "aeiou";
    int i, j, result = -1;
    for (i = 0; s1[i] && result == -1; i++)
        for (j = 0; s2[j]; j++)
            if (s1[i] == s2[j]) { result = i; break; }
    printf("%d\n", result);
    return 0;
}
