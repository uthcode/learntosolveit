/* Concept: file copy using open/creat — read chunks, write chunks */
#include <stdio.h>
int main(void) {
    char src[] = "hello\n";
    char buf[10];
    int n = 6, i;
    printf("Copying %d bytes:\n", n);
    for (i = 0; i < n; i++) buf[i] = src[i];
    for (i = 0; i < n; i++) putchar(buf[i]);
    return 0;
}
