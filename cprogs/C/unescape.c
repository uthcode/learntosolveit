/* function unescape */
#include<stdio.h>
#define MAXLINE 1000

void unescape(char s[],char t[]);
int getline(char line[],int maxlimit);

int main(void)
{
	char s[MAXLINE],t[MAXLINE];

	getline(t,MAXLINE);

	unescape(s,t);
	
	printf("%s",s);
	
	return 0;
}

void unescape(char s[],char t[])
{
	int i,j;

	for(i=j=0;t[i]!='\0';++i)
		switch(t[i])
		{
			case '\\':
				switch(t[++i])
				{
					case 'n':
						s[j++]='\n';
						break;
					case 't':
						s[j++]='\t';
						break;
					default:
						s[j++]='\\';
						s[j++]=t[i];
						break;
				}
				break;
			default:
				s[j++]=t[i];
				break;
		}
		s[j]='\0';
}

int getline(char s[],int lim)
{
	int i,c;
	
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c !='\n';++i)
		s[i]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
}

