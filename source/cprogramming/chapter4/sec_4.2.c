/**
 *
 * Section 4.2  The C Programming Language
 *
 * Convert the string s to a double.
 */

#include <ctype.h>
#include <stdio.h>

double atof(char s[]);

int main(int argc, char *argv[]) {
    char s[8] = "1234.56";
    double d = atof(s);
    printf("%f\n", d);
    return 0;
}

double atof(char s[]) {
    double val, power;
    int i, sign;

    /** Skip white space */
    for (i = 0; isspace(s[i]); i++) {
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return (sign * val) / power;
}
