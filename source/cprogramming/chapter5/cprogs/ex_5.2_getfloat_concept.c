/* Concept: getfloat reads a floating-point number via a pointer */
#include <stdio.h>
int getfloat(float *pn) {
    char s[] = "3.14";
    int i = 0;
    float pow = 1.0;
    *pn = 0;
    while (s[i] >= '0' && s[i] <= '9') { *pn = *pn * 10 + (s[i] - '0'); i++; }
    if (s[i] == '.') {
        i++;
        while (s[i] >= '0' && s[i] <= '9') { pow *= 10; *pn += (s[i] - '0') / pow; i++; }
    }
    return i > 0 ? 1 : 0;
}
int main(void) {
    float n;
    if (getfloat(&n) > 0) printf("%.2f\n", n);
    return 0;
}
