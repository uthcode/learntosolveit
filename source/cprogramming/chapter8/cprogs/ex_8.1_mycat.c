#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

/* error: print an error message and die */
void error(char *fmt, ...) {
    /* standard method to print error message with variable argument list. */
    va_list args;
    va_start(args, fmt);

    fprintf((FILE *) STDERR, "error: ");

    vfprintf((FILE *) STDERR, fmt, args);
    fprintf((FILE *) STDERR, "\n");
    va_end(args);
    exit(1);
}

/* filecopy: copy file ifd to ofd */
void filecopy(int ifd, int ofd) {
    int n;
    char buf[BUFSIZ];

    /* read and write using the system calls. */

    while ((n = read(ifd, buf, BUFSIZ)) > 0)
        if (write(ofd, buf, n) != n) {
            error("cat: write error");
        }
}

/* cat: concatenate files - read/write/open/close */

int main(int argc, char *argv[]) {
    int fd;

    if (argc == 1) {
        /* get from stdin and write to stdout. */
        filecopy(STDIN, STDOUT);
    } else
        /* cat all the files one by one. */
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY)) == -1) {
                error("cat:can't open %s", *argv);
            } else {
                filecopy(fd, STDOUT);
                close(fd);
            }
    return 0;
}