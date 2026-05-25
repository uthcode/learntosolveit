/* Concept: convert string to double, including decimal point */
#include <ctype.h>
#include <stdio.h>
double myatof(char s[]) {
    double val = 0.0, pow = 1.0;
    int i = 0, sign = 1;
    if (s[i] == '-') { sign = -1; i++; }
    for (; isdigit(s[i]); i++) val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.') i++;
    for (; isdigit(s[i]); i++) { val = 10.0 * val + (s[i] - '0'); pow *= 10.0; }
    return sign * val / pow;
}
int main(void) {
    printf("%f\n", myatof("3.14"));
    printf("%f\n", myatof("-2.5"));
    return 0;
}
