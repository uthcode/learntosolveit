/* Concept: argv[0] selects operation — tolower vs toupper */
#include <stdio.h>
#include <ctype.h>
int main(void) {
    char s[] = "Hello";
    int i;
    /* argv[0] == "lower": convert to lowercase */
    for (i = 0; s[i]; i++) putchar(tolower((unsigned char)s[i]));
    putchar('\n');
    /* argv[0] == "upper": convert to uppercase */
    for (i = 0; s[i]; i++) putchar(toupper((unsigned char)s[i]));
    putchar('\n');
    return 0;
}
