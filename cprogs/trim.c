/* trim: remove the trailing blanks, tabs and newlines - usage of break */

#include<stdio.h>
#define MAXLINE 100

int getline(char s[],int maxlimit);
int trim(char s[]);

int main(void)
{
	char s[MAXLINE];

	printf(":%d",getline(s,MAXLINE));

	printf("\n:%d",trim(s));

	return 0;
}

int getline(char s[],int lim)
{
	int i,c;

	for(i=0;i<lim-1 &&(c=getchar())!=EOF && c!='\n';++i)
		s[i]=c;

	if(c=='\n')
		s[i++]=c;

 	s[i]='\0';

	return i;
}

int trim(char s[])
{
	int n;
	
	for(n=strlen(s)-1;n>=0;n--)
		if(s[n]!=' '&& s[n]!='\t'&&s[n]!='\n')
			break;

	s[n+1]='\0';
	
	return n;
}

