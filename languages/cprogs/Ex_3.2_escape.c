/* Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a Switch. Write a function for 
the other direction as well,converting the escape sequences into the real characters */

#include<stdio.h>
#define MAXLINE 1000
int mgetline(char line[],int maxline);
void escape(char s[],char t[]);


int main(void)
{
	char s[MAXLINE],t[MAXLINE];

	putchar('t');
	mgetline(t,MAXLINE);

	escape(s,t);

	printf("%s",s);

	return 0;
}

void escape(char s[],char t[])
{
	int i,j;

	i=j=0;

	while(t[i] != '\0')
	{
		switch(t[i])
		{
			case '\t':
					s[j]='\\';
					++j;
					s[j]='t';
					break;
			case '\n':
					s[j]='\\';
					++j;
					s[j]='n';
					break;
			default:
					s[j]=t[i];
					break;
		}
		++i;
		++j;
	}
	
	s[j]='\0';
}

int mgetline(char s[],int lim)
{
	int i,c;

	for(i=0;i<lim-1 && (c=getchar())!=EOF && c !='\n';++i)
		s[i]=c;

	if(c=='\n')
		s[i++]=c;
	
	s[i]='\0';
}

