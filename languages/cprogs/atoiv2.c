/* Ex5.6 */

#include <stdio.h>
#include <ctype.h>

int atoiv2(char *);

int main(void) {
    char *s = "1234";
    int ret;

    ret = atoiv2(s);

    printf("%d", ret);

    return 0;
}

int atoiv2(char *s) {
    int n, sign;

    for (; isspace(*s); s++)    /* skip white space */
        ;
    sign = (*s == '-') ? -1 : 1;

    if (*s == '+' || *s == '-')
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + *s - '0';

    return sign * n;
}

