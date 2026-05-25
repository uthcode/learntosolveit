/* Concept: recursive itoa builds digits from most significant first */
#include <stdio.h>
#include <stdlib.h>
void itoa(int n, char s[]) {
    static int i;
    if (n / 10) itoa(n / 10, s);
    else { i = 0; if (n < 0) s[i++] = '-'; }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}
int main(void) {
    char s[20];
    itoa(42, s);
    printf("%s\n", s);
    return 0;
}
