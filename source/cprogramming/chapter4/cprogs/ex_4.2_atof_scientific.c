/**
 * Exercise 4.2 - Extend atof to handle scientific notation of the form
 * 123.45e-6 where a floating-point number may be followed by e or E and
 * an optionally signed exponent.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

double atof(char s[]);
int mgetline(char s[], int lim);

int main(int argc, char *argv[])
{
    char str[MAXLINE];
    double val;

    mgetline(str, MAXLINE);

    val = atof(str);

    printf("%f", val);

    return 0;
}

double atof(char s[])
{
    double val, pow;
    int sign, i, esign, exp;

    int power(int base, int exp);

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (pow = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        pow *= 10.0;
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;

    if (s[i] == '+')
        esign = 1;
    else if (s[i] == '-')
        esign = -1;
    else
        esign = 1;

    for (exp = 0; isdigit(s[i]); i++)
        exp = 10 * exp + (s[i] - '0');

    if (esign == 1)
        val = (val / pow) * power(exp, 10);
    else
        val = (val / pow) / power(exp, 10);

    return sign * val;
}

int mgetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

int power(int base, int exp)
{
    int i, p;

    p = 1;

    for (i = 1; i <= exp; ++i)
        p = p * base;

    return p;
}
