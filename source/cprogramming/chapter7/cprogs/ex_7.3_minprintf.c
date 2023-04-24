/* minprintf: minimalistic printf function */
#include <stdarg.h>
#include <stdio.h>

void minprintf(char *fmt, ...);

int main(void) {
    char *a = "Hello,World";
    minprintf("%s", a);
    int i = 10;
    minprintf("%d\n", i);
    int b = 011;
    minprintf("b in octal: %o, and in decimal: %d\n", b, b);
    int h = 10;
    minprintf("h in hex: %x, and in decimal: %d\n", h, h);
    return 0;
}

void minprintf(char *fmt, ...) {
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'o':
                ival = va_arg(ap, int);
                printf("%o", ival);
                break;
            case 'x':
                ival = va_arg(ap, int);
                printf("%x", ival);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* clean up when done */
}
