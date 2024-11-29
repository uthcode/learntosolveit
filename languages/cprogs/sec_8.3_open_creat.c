#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define PERMS 0666 /* RW for owner, group and others */

#define BUFSIZ 1024

void merror(char *, ...);

int main(int argc, char *argv[])
{
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


void merror(char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}
