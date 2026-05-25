/* Concept: walk both pointers to ends, then compare backwards for suffix */
#include <stdio.h>
int strend(char *s, char *t) {
    char *ps = s, *pt = t;
    while (*ps) ps++;
    while (*pt) pt++;
    while (pt > t && ps > s && *--pt == *--ps);
    return *pt == *ps;
}
int main(void) {
    printf("%d\n", strend("hello", "lo")); /* 1 */
    printf("%d\n", strend("hello", "hi")); /* 0 */
    return 0;
}
