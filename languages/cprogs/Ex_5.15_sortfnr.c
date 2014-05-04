/* Add the option -f to fold upper and lower cases together, so that case distinctions are not made clearly during sorting;For eg:a and A compare equal */

#include<stdio.h>
#include<string.h>
#include<ctype.h>


#define NUMERIC 1	/* numeric sort */
#define DECR	2	/* sort in decreasing order */
#define FOLD	4	/* fold upper and lower cases */
#define LINES	100	/* maximum numnber of lines to be sorted */


int charcmp(char *,char *);
int numcmp(char *,char *);
int readlines(char *lineptr[],int maxlines);
void myqsort(char *v[],int left,int right,int (*comp)(void *,void *));
void writelines(char *lineptr[],int nlines,int order);

static char option = 0;

/* sort input lines */

int main(int argc,char *argv[])
{
	char *lineptr[LINES];	/* pointers to text lines */
	int nlines;		/* number of input lines read */
	int c,rc=0;

	while(--argc > 0 && (*++argv[0] == '-'))
		while(c = *++argv[0])
			switch(c)
			{
				case 'f':
						option |= FOLD;
						break;
				case 'n':
						option |= NUMERIC;
						break;
				case 'r':
						option |= DECR;
						break;
				default:
						printf("sort: illegal option %c\n",c);
						argc=1;
						rc=-1;
						break;
			}
	if (argc)
		printf("Usage: sort -fnr \n");
	else
	{
		if((nlines=readlines(lineptr,LINES)) > 0)
		{
			if(option & NUMERIC)
				myqsort((char **)lineptr,0,nlines-1,(int (*)(void *,void *))numcmp);
			else if ( option & FOLD)
				myqsort((char **)lineptr,0,nlines-1,(int (*)(void *,void *))charcmp);
			else
				myqsort((char **)lineptr,0,nlines-1,(int (*)(void *,void *))strcmp);

			writelines(lineptr,nlines,option & DECR);
		}
		else
		{
			printf("input too big to sort \n");
			rc = -1;
		}

	return rc;
	
	}

/* charcmp: return < 0 if s <t, =0 if s =t,> 0 if s > t */
int charcmp(char *s,char *t)
{
	for(;tolower(*s) == tolower(*t);s++,t++)
		if(*s == '\0')
			return 0;
	return tolower(*s) - tolower(*t);
}

#include<stdlib.h>
/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1,char *s2)
{
	double v1,v2;
	v1 = atof(s1);
	v2 = atof(s2);
	
	if(v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

#define MAXLEN	1000 		/* max length of any input line */
int mgetline(char *,int);
char *alloc(int);

/* readlines: read input lines */

int readlines(char *lineptr[],int maxlines)
{
	int len,nlines;
	char *p,line[MAXLEN];

	nlines = 0;
	while((len=mgetline(line,MAXLEN))>0)
		if(nlines >= maxlines || (p=alloc(len)) == NULL)
			return -1;
		else
		{
			line[len-1]='\0';	/* delete newline */
			strcpy(p,line);
			lineptr[nlines++]=p;
		}
	return nlines;
}

/* myqsort: sort v[left] ... v[right] into increasing order */

void myqsort(char *v[],int left,int right)
{
	int i,last;
	void swap(char *v[],int i,int j);

	if(left>=right)	/* do nothing if array contains */
		return;	/*fewer that two elements */

	swap(v,left,(left+right)/2);

	last=left;

	for(i = left + 1; i <=right;i++)
		if(strcmp(v[i],v[left]) < 0)
			swap(v,++last,i);
	swap(v,left,last);
	myqsort(v,left,last-1);
	myqsort(v,last+1,right);
}

/* swap: interchange v[i] and v[j] */

void swap(char *v[],int i,int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


/* writelines: write output line */

void writelines(char *lineptr[],int nlines)
{
	int i;
	for(i=0;i<nlines;i++)
		printf("%s\n",lineptr[i]);
}

#define ALLOCSIZE 1000	/* size of available space */
static char allocbuf[ALLOCSIZE];	/* storage for alloc */
static char *allocp = allocbuf;		/* next free position */

char *alloc(int n)	/* return pointer to n characters */
{
	if(allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n ;
		return allocp - n;
	}
	else
		return 0;
}

void afree(char *p)		/* free storage pointed to by */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

/* mgetline: read a line into s, return length */

int mgetline(char s[],int lim)
{
	int c,i;
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if( c == '\n')
	{
		s[i] =c;	
		++i;
	}
	s[i] = '\0';
	return i;

}

