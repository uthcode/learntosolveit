/* Concept: frequency histogram tracking only 'a', 'b', 'c' */
#include <stdio.h>
int main(void) {
    char s[] = "aab";
    int cnt[3] = {0};
    int i, j;
    for (i = 0; s[i]; ++i)
        if (s[i] >= 'a' && s[i] <= 'c') cnt[s[i]-'a']++;
    for (i = 0; i < 3; ++i) {
        putchar('a'+i);
        for (j = 0; j < cnt[i]; ++j) putchar('*');
        putchar('\n');
    }
    return 0;
}
