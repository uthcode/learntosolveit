#include <stdio.h>

#define ALLOCSIZE 1000              /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
	if( allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n; /* old p */
	}
	else
		return 0;
}


void afree(char *p)	/* free storage pointed to by p */
{
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

int main(void)
{
	char *p;
	printf("%p\n",allocp);

	p=alloc(100);
	printf("%p\n",allocp);

	afree(p);
	printf("%p\n",allocp);

	return 0;
}


