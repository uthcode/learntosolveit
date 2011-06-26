#include<stdio.h>
#include<string.h>
void itoav2(int n,char *s);
void reverse(char *);

int main(void)
{
	char s[100];
	int i=12345;
	itoav2(i,s);
	reverse(s);
	printf("%s",s); 
	
	return 0;
}

void itoav2(int n,char *s)
{
	int sign;
	char *t=s;
	
	if((sign = n) < 0)
		n = -n;

	do
	{
		*s++ = n % 10 + '0';
	} while ((n /= 10) > 0);

	if(sign < 0)
		*s++ = '-';
	*s='\0';

}

void reverse(char *s)
{
	int c;
	char *t;

	for(t=s+(strlen(s)-1);s<t;s++,t--)
	{
		c=*s;
		*s=*t;
		*t=c;
	}
}
