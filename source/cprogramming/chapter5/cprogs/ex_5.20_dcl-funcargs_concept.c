/* Concept: tokenize a C declaration — identify *, [], (), names */
#include <stdio.h>
#include <ctype.h>
int main(void) {
    char *s = "(*fp)(int)";
    int i = 0;
    char c;
    while ((c = s[i++])) {
        if (c == '(')       printf("function/group ");
        else if (c == '*')  printf("pointer ");
        else if (isalpha(c)) {
            printf("name ");
            while (isalpha(s[i])) i++;
        } else if (c == '[') {
            printf("array ");
            while (s[i] && s[i] != ']') i++;
            i++;
        }
    }
    printf("\n");
    return 0;
}
