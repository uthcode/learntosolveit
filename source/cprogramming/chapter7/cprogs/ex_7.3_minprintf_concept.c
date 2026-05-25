/* Concept: variadic function using va_list to handle %s and %d */
#include <stdarg.h>
#include <stdio.h>
void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') { putchar(*p); continue; }
        switch (*++p) {
            case 'd': ival = va_arg(ap, int); printf("%d", ival); break;
            case 's': for (sval = va_arg(ap, char *); *sval; sval++) putchar(*sval); break;
            default:  putchar(*p); break;
        }
    }
    va_end(ap);
}
int main(void) {
    minprintf("hi %s\n", "world");
    minprintf("%d\n", 42);
    return 0;
}
