/* rudimentary calculator, which reads one number per line, optionally preceded by a sign and adds
 them up, printing the running sum after each input */

#include<stdio.h>
#include<ctype.h>
#define MAXLINE 100

int getline(char line[],int maxline);
double atof(char s[]);

int main(void)
{
	double sum,atof(char s[]);
	char line[MAXLINE];

	int getline(char line[],int max);

	sum = 0;

	while(getline(line,MAXLINE)>0)
		printf("\t%g\n",sum+=atof(line));

	return 0;
}

int getline(char s[],int lim)
{
	int i,c;

	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';i++)
		s[i]=c;

	if(c=='\n')
		s[i++]=c;

	s[i]='\0';
	return i;
}

/* atof: function that converts the string to floating value */

double atof(char s[])
{
	double val,pow;
	int i,sign;

	for(i=0;isspace(s[i]);i++)
		;
	sign=(s[i]=='-')?-1:1;
	
	if(s[i]=='+' || s[i]=='-')
		i++;
	
	for(val=0.0;isdigit(s[i]);i++)
		val = 10.0 * val + (s[i] - '0');
	
	if(s[i]=='.')
		i++;
	
	for(pow=1.0;isdigit(s[i]);i++)
	{
		val= 10.0 * val + (s[i] - '0');
		pow *= 10.0;
	}

	return sign * val / pow;
}
 
