/* Longest Line Program using External Variables*/

#include<stdio.h>
#define MAXLEN 1000

char line[MAXLEN],longest[MAXLEN];

int getline(void);
void copy(void);

int main(void)
{
	int len,max;
	max = 0;
	while((len=getline())>0)
	{
		if( len > max)
		{
		  max = len;
		  copy();
		}
	}
	if( max > 0)
		printf("%s",longest);

	return 0;
}
int getline()
{
	int c,i;
	
	for(i=0;i<MAXLEN -1 &&(c=getchar())!=EOF && c!= '\n';++i)
		line[i] = c;
	if( c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
void copy()
{
	int i;
	i = 0;
	while((longest[i]=line[i])!='\0')
		++i;
}
 
	
