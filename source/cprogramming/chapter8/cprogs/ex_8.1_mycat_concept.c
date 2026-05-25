/* Concept: read() fills a buffer; write() drains it — the copy loop */
#include <stdio.h>
int main(void) {
    char src[] = "hello\n";
    char buf[8];
    int i, n = 6;
    for (i = 0; i < n; i++) buf[i] = src[i];
    buf[n] = '\0';
    for (i = 0; i < n; i++) putchar(buf[i]);
    return 0;
}
