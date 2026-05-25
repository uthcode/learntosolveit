/* Concept: read into buffer and write from buffer — the copy loop pattern */
#include <stdio.h>
int main(void) {
    char src[] = "hi\n";
    char buf[4];
    int n = 3, i;
    for (i = 0; i < n; i++) buf[i] = src[i];
    for (i = 0; i < n; i++) putchar(buf[i]);
    return 0;
}
