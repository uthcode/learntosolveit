/* Concept: convert escape chars \t and \n to visible two-char sequences */
#include <stdio.h>
void escape(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i]) {
        switch (t[i]) {
            case '\t': s[j++] = '\\'; s[j] = 't'; break;
            case '\n': s[j++] = '\\'; s[j] = 'n'; break;
            default:   s[j] = t[i]; break;
        }
        i++; j++;
    }
    s[j] = '\0';
}
int main(void) {
    char t[] = "a\tb\n";
    char s[20];
    escape(s, t);
    printf("%s\n", s);
    return 0;
}
