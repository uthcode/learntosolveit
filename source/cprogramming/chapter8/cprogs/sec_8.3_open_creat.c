#include <fcntl.h>      // For file control options like O_RDONLY
#include <stdarg.h>     // For variable argument functions
#include <stdio.h>      // For standard I/O
#include <sys/syscall.h> // For system calls
#include <unistd.h>     // For UNIX standard functions like read/write
#include <stdlib.h>     // For exit()

#define PERMS 0666     // File permissions: read/write for all users
#define BUFSIZ 1024    // Buffer size for reading/writing

#define PERMS 0666 /* RW for owner, group and others */

#define BUFSIZ 1024

void merror(char *, ...);

int main(int argc, char *argv[]) {
    int f1, f2, n;
    char buf[BUFSIZ];

    if (argc != 3)
        merror("Usage: prog: from to");

    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
        merror("prog: can't open %s", argv[1]);
    if ((f2 = creat(argv[2], PERMS)) == -1)
        merror("prog: can't create %s, mode %03o", argv[2], PERMS);

    while ((n = read(f1, buf, BUFSIZ)) > 0)
        if (write(f2, buf, n) != n)
            merror("prog: write error on file %s", argv[2]);

    return 0;
}

/**
fmt is the format string parameter
... (ellipsis) indicates variable number of arguments can follow

*/
void merror(char *fmt, ...) {
    va_list args;  // Declares a variable to hold the argument list
    va_start(args, fmt);  // Initialize 'args' to start after 'fmt'
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args); // Print formatted output using args list
    fprintf(stderr, "\n");
    va_end(args); // cleans up variable arguments.
    exit(1);
}
