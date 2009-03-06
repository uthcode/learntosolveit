/* to illustrate the comma operator by using it in  a  C Program */

#include<stdio.h>
#include<string.h>
#define MAXLINE 100

void myreverse(char s[]);

int main(void)
{
	char str[MAXLINE];

	getline(str,MAXLINE);

	myreverse(str);
	printf("%s",str);

	return 0;
}

void myreverse(char s[])
{
	int c,i,j;

	for(i=0,j=strlen(s)-1;i<j;i++,j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int getline(char s[],int lim)
{
	int i,c;
	
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
		s[i] = c;

	if(c=='\n')
		s[i++]=c;

	if(c=='\0')
		s[i]='\0';
}



