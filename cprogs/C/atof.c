/* Program demonstrating atof(char s[]).The function which converts the string to a floating 
   point value */
#include<stdio.h>
#include<ctype.h>
#define MAXLINE 100

double myatof(char s[]);
int getline(char line[],int maxline);

int main(void)
{
	char str[MAXLINE];
	double num;
	getline(str,MAXLINE);

	num=myatof(str);
	printf("%f",num);

	return 0;
}

double myatof(char s[])
{
	double val,pow;
	int sign,i;	
	
	for(i=0;isspace(s[i]);i++)
		;

	sign=(s[i]=='-')?-1:1;

	if(s[i]=='+' || s[i] == '-')
		i++;

	for(val=0.0;isdigit(s[i]);i++)
		val = 10.0 * val + (s[i] - '0');
	
	if(s[i]=='.')
		i++;

	for(pow=1.0;isdigit(s[i]);i++)
	{
		val = 10.0 * val + (s[i] - '0');
		pow *= 10.0;
	}

	return sign * val / pow;
}

int getline(char s[],int lim)
{
	int i,c;

	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
		s[i] = c;
	
	if(c=='\n')
		s[i++]=c;

	s[i]='\0';
}
	

	
	
