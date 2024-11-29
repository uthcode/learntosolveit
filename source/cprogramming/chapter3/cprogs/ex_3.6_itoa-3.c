#include <stdio.h>
#include <string.h>

#define MAXLIMIT 100

void reverse(char s[]) {
    int i, j, c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

void itoa(int n, char s[], int w) {
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;

    do {
        s[i++] = (n % 10) + '0';

    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    while (i < w)
        s[i++] = ' ';

    s[i] = '\0';

    reverse(s);
}

int main(void) {
    int number, width;
    char str[MAXLIMIT];

    number = -343565;
    width = 10;

    itoa(number, str, width);

    printf("%s", str);

    return 0;
}