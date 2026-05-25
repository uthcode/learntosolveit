/* Concept: getint reads an integer via a pointer argument */
#include <stdio.h>
int getint(int *pn) {
    char s[] = "42";
    int i = 0;
    *pn = 0;
    while (s[i] >= '0' && s[i] <= '9') { *pn = *pn * 10 + (s[i] - '0'); i++; }
    return i > 0 ? 1 : 0;
}
int main(void) {
    int n;
    if (getint(&n) > 0) printf("%d\n", n);
    return 0;
}
