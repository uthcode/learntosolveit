#include<stdio.h>
/* echo command-line arguments: 2nd version */
int main(int argc,char *argv[])
{
	while(--argc > 0)
		printf("%s %s",*++argv,(argc > 1)? " ": "");
	printf("\n");
	return 0;
}

