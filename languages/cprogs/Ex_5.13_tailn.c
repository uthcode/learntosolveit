/* Write a Program tail, which prints the last n lines of its input. By default n is 10. let us say; but it can be changed
by an optional argument so that tail -n */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFLINES 10 /* default # of lines to print */
#define LINES	100	/* maximum # of lines to print */
#define MAXLEN	100	/* maximum length of an input line */

void error(char *);
int mgetline(char *,int);

/* print the last n lines of the input */

int main(int argc,char *argv[])
{
	char *p;
	char *buf;	/* pointer to the large buffer */
	char *bufend;	/* end of the large buffer */

	char line[MAXLEN];
	char *lineptr[LINES];	/* pointer to lines read */
	
	int first,i,last,len,n,nlines;

	if( argc == 1)
		n = DEFLINES;

	else if(argc ==2 && (*++argv)[0] == '-')
		n = atoi(argv[0]+1);
	else
		error("Usage: tail [-n]");

	if( n < 1 || n > LINES)
			n = LINES;

	for(i = 0; i < LINES; i++)
			lineptr[i] = NULL;

	if(( p = buf = malloc(LINES * MAXLEN)) == NULL)
		error("tail: cannot allocate buf");
	bufend = buf + LINES + MAXLEN;

	last = 0;
	nlines = 0;

	while((len = mgetline(line,MAXLEN)) > 0)
	{
		if(p+len+1 >= bufend)
			p = buf;
		lineptr[last] = p;

		strcpy(lineptr[last],line);
		if(++last >= LINES)
			last = 0;

		p += len + 1;
		nlines++;
	}

	if( n > nlines)
		n = nlines;

	first = last - n;

	if(first < 0)
		first += LINES;
	
	for(i= first; n-- > 0;i = (i+1) % LINES)
		printf("%s",lineptr[i]);

	return 0;
}

/* error: print error messages and exit */

void error(char *s)
{
	printf("%s\n",s);
	exit(1);
}

/* mgetline: read a line into s and return length */

int mgetline(char s[],int lim)
{
	int c,i;
	
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
		s[i] = c;
	if ( c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

