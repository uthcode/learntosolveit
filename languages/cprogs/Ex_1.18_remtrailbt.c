/* Write a Program to remove the trailing blanks and tabs from each input line
	and to delete entirely blank lines */

#include<stdio.h>
#define MAXLINE 1000

int mgetline(char line[],int lim);
int removetrail(char rline[]);

int main(void)
{
	int len;
	char line[MAXLINE];
	
	while((len=mgetline(line,MAXLINE))>0)
		if(removetrail(line) > 0)
			printf("%s",line);

	return 0;
}

int mgetline(char s[],int lim)
{
	int i,c;

	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
		s[i] = c;
	if( c == '\n')
	{
		s[i]=c;
		++i;
	}
	s[i]='\0';
	
	return i;
}

/* To remove Trailing Blanks,tabs. Go to End and proceed backwards removing */

int removetrail(char s[])
{
	int i;

	for(i=0; s[i]!='\n'; ++i)
		;
	--i;  /* To consider raw line without \n */

	for(i >0; ((s[i] == ' ') || (s[i] =='\t'));--i) 	
		; /* Removing the Trailing Blanks and Tab Spaces */

	if( i >= 0) /* Non Empty Line */
	{
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}
	return i;
}

