/* Write a Program to Count Blanks, Tabs and Newlines */

#include<stdio.h>

int main(void)
{
	int nb,nt,nl,c;

	nb=nt=nl=0;

	while((c=getchar())!=EOF)
	{
		if(c==' ')
			++nb;
		if(c=='\t')
			++nt;
		if(c=='\n')
			++nl;
	}
	printf("No. of Blanks is %d,No. of Tabs is %d and No. of Newlines is %d",nb,nt,nl);

return 0;
}

