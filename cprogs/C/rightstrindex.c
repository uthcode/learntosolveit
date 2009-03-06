/* pattern matching program */
#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

int getline(char line[],int maxline);
int strrindex(char source[],char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all the matching patterns */

int main(void)
{
	char line[MAXLINE];

	int found=0,occurance;

	getline(line,MAXLINE);
	occurance=strrindex(line,pattern);
	printf("%d",occurance);

	return found;
}

int getline(char s[],int lim)
{
	int c,i;

	i=0;

	while(--lim > 0 && (c=getchar())!=EOF && c !='\n')
		s[i++] =c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';

	return i;
}

int strrindex(char s[],char t[])
{
	int i,j,k;

	for(i=strlen(s)-1;i>0;i--)
	{
		for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
			;
		if(k>0 && t[k] == '\0')
			return i;
	}
	return -1;
}

