/* Concept: convert integer to string in arbitrary base */
#include <stdio.h>
#include <string.h>
void reverse(char s[]) {
    int i = 0, j = strlen(s) - 1, c;
    for (; i < j; i++, j--) c = s[i], s[i] = s[j], s[j] = c;
}
void itob(int n, char s[], int b) {
    int i = 0, j, sign;
    if ((sign = n) < 0) n = -n;
    do {
        j = n % b;
        s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    } while ((n /= b) > 0);
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
int main(void) {
    char str[20];
    itob(42, str, 16);
    printf("%s\n", str);  /* 2a */
    return 0;
}
