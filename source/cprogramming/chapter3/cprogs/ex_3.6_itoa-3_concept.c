/* Concept: itoa with minimum field width padding */
#include <stdio.h>
#include <string.h>
void reverse(char s[]) {
    int i = 0, j = strlen(s) - 1, c;
    for (; i < j; i++, j--) c = s[i], s[i] = s[j], s[j] = c;
}
void itoa(int n, char s[], int w) {
    int i = 0, sign;
    if ((sign = n) < 0) n = -n;
    do { s[i++] = (n % 10) + '0'; } while ((n /= 10) > 0);
    if (sign < 0) s[i++] = '-';
    while (i < w) s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}
int main(void) {
    char str[20];
    itoa(42, str, 6);
    printf("[%s]\n", str);  /* [    42] */
    return 0;
}
