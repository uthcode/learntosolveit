#include<stdio.h>
/*echo command - line arguments: 3rd version */
int main(int argc,char *argv[])
{
	while( --argc >0)
	printf((argc > 1)?"%s ":"%s",*++argv);
	printf("\n");
}

