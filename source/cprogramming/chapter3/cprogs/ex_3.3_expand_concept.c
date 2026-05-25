/* Concept: expand shorthand range a-d into abcd */
#include <stdio.h>
void expand(char s1[], char s2[]) {
    int i = 0, j = 0, c;
    while ((c = s1[i++]))
        if (s1[i] == '-' && s1[i+1] >= c) {
            i++;
            while (c < s1[i]) s2[j++] = c++;
        } else s2[j++] = c;
    s2[j] = '\0';
}
int main(void) {
    char s2[20];
    expand("a-d", s2);
    printf("%s\n", s2);  /* abc */
    return 0;
}
