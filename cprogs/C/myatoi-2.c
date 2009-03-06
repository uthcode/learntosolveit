/* myatoi.c : convert str to integer version 2 */

#include<stdio.h>
#define MAXLINE 100
int myatoi(char s[]);

int main(void)
{
	char s[MAXLINE];

	getline(s,MAXLINE);

	printf("%d",myatoi(s));

	return 0;
}

int myatoi(char s[])
{
	int i,n,sign;

	for(i=0;isspace(s[i]);i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	
	if(s[i] == '+' || s[i] == '-')
		i++;
	
	for(n=0;isdigit(s[i]);i++)
		n = 10 * n + (s[i] - '0');
	
	return sign * n;
}

int getline(char s[],int lim)
{
	int i,c;

	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
		s[i]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
}

