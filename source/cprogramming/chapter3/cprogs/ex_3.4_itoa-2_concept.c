/* Concept: itoa using do-while to handle INT_MIN correctly */
#include <stdio.h>
#include <string.h>
#define abs(x) ((x) > 0 ? (x) : -(x))
void reverse(char s[]) {
    int i = 0, j = strlen(s) - 1, c;
    for (; i < j; i++, j--) c = s[i], s[i] = s[j], s[j] = c;
}
void itoa(int n, char s[]) {
    int i = 0, sign = n;
    do { s[i++] = abs(n % 10) + '0'; } while ((n /= 10) != 0);
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
int main(void) {
    char str[20];
    itoa(-42, str);
    printf("%s\n", str);
    return 0;
}
