/* itoa: convert an integer to string */
#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

void itoa(int n,char s[]);
void reverse(char s[]);

int main(void)
{
	int number;
	char str[MAXLINE];

/* 	number=-2345645;
checking with the limits */
	
	number = -2147483648;

	
	printf("Integer %d printed as\n String:",number);

	itoa(number,str);

	printf("%s",str);

	return 0;
}

void itoa(int n,char s[])
{
	int i,sign;

	if((sign=n) < 0)
		n = -n;

	i = 0;

	do
	{
		s[i++]=(n%10) + '0';
	
	}while((n/=10)>0);
	
	if( sign < 0)
		s[i++]='-';

	s[i]='\0';

	reverse(s);
}

void reverse(char s[])
{
	int c,i,j;

	for(i=0,j=strlen(s)-1;i<j;i++,j--)
		c=s[i],s[i]=s[j],s[j]=c;
}
	
