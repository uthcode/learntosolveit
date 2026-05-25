/* Concept: varargs — va_start/va_arg dispatch on format specifier */
#include <stdio.h>
#include <stdarg.h>
void show_args(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    char *p;
    for (p = fmt; *p; p++) {
        if (*p != '%') continue;
        switch (*++p) {
            case 'd': printf("int: %d\n",  va_arg(ap, int));   break;
            case 's': printf("str: %s\n",  va_arg(ap, char*)); break;
        }
    }
    va_end(ap);
}
int main(void) {
    show_args("%d%s", 42, "hello");
    return 0;
}
