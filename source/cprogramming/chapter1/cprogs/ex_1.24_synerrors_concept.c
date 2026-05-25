/* Concept: count braces and parentheses to check balance */
#include <stdio.h>
int main(void) {
    char s[] = "if (x) { y; }";
    int brace = 0, paren = 0, i = 0, c;
    while ((c = (int)(unsigned char)s[i++])) {
        if (c == '{') ++brace;
        else if (c == '}') --brace;
        else if (c == '(') ++paren;
        else if (c == ')') --paren;
    }
    if (brace != 0) printf("Unmatched braces\n");
    else if (paren != 0) printf("Unmatched parenthesis\n");
    else printf("Balanced\n");
    return 0;
}
