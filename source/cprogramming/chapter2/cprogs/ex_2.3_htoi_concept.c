/* Concept: convert hex string to integer */
#include <stdio.h>
int main(void) {
    char s[] = "ff";
    int i, val = 0, digit;
    for (i = 0; s[i]; i++) {
        if      (s[i] >= '0' && s[i] <= '9') digit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f') digit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F') digit = s[i] - 'A' + 10;
        else break;
        val = val * 16 + digit;
    }
    printf("0x%s = %d\n", s, val);
    return 0;
}
