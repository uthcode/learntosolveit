/*
 * Write a program to print a set of files, starting each new one on a new page, 
 * with a title and a running page count for each file.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELENGTH 80
#define LINESPERPAGE 10

void printpages(FILE *, FILE *);

int main(int argc, char *argv[]) {
	FILE *fp;
	char *prog = argv[0];
	int linecount = 0;

	if (argc == 1) /* no args; copy standard input */
	{
		fprintf(stderr, "No files given");
		printpages(stdin, stdout);
	}
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "%s: can't open %s\n",
						prog, *argv);
				exit(1);
			} else {
				fprintf(stdout, "\n\n\t\t\tFile: %s\n\n", *argv);
				printpages(fp, stdout);
				fclose(fp);
			}

	if (ferror(stdout)) {
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}
	exit(0);
}

/* filecopy: copy file ifp to file ofp */

void printpages(FILE *ifp, FILE *ofp)
{
	int c;
	int line=0;
	int pg=1;

	while ((c = getc(ifp)) != EOF)
	{
		putc(c, ofp);
		if (c == '\n') {
			line = line + 1;
			if (line == LINESPERPAGE)
			{
				fprintf(stdout, "\n\t\t\tPage %d End.\n\n", pg);
				pg = pg + 1;
				line = 0;
			}
		}

	}
}
