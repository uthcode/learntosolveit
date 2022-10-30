/*copy input to output */

#include <sys/syscall.h>
#include <unistd.h>

#define BUFSIZ 1024

int main() /* copy input to output */
{
    char buf[BUFSIZ];
    int n;

    while ((n = read(0, buf, BUFSIZ)) > 0)
        write(1, buf, n);
    return 0;
}
