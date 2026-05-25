/* Concept: sort strings in reverse numeric order using function pointer */
#include <stdio.h>
int numcmp(char *s1, char *s2) {
    int n1 = 0, n2 = 0;
    while (*s1 >= '0' && *s1 <= '9') n1 = n1*10 + *s1++ - '0';
    while (*s2 >= '0' && *s2 <= '9') n2 = n2*10 + *s2++ - '0';
    return n2 - n1;
}
int main(void) {
    char *lines[3] = {"3", "1", "2"};
    int i, j;
    char *tmp;
    for (i = 0; i < 2; i++)
        for (j = i+1; j < 3; j++)
            if (numcmp(lines[i], lines[j]) > 0) { tmp = lines[i]; lines[i] = lines[j]; lines[j] = tmp; }
    for (i = 0; i < 3; i++) printf("%s\n", lines[i]);
    return 0;
}
