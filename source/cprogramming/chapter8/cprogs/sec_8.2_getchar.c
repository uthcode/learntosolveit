/* Example of an unbuffered and buffered getchar */

#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

#define BUFSIZ 1024

/* unbuffered getchar implementation using read */

int ugetchar(void);

/* buffered getchar implementation using read */
int bgetchar(void);

int main() {
    char c;
    while ((c = ugetchar()) != 'x') {
        putchar(c);
    }

    while ((c = bgetchar()) != 'x') {
        putchar(c);
    }

    return 0;
}

int ugetchar(void) {
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char)c : EOF;
}

int bgetchar(void) {
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) /* buffer is empty */
    {
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }

    return (--n >= 0) ? (unsigned char)*bufp++ : EOF;
}
