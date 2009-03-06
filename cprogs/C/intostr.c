#include<stdio.h>
#include<string.h>
int main(void)
{
	char *p,text[10];
	int i = 132;
	
	sprintf(text,"%d",i);

	p = text;

	printf("p points to the string \"%s\"\n",p);
	
	printf("the length of p is %d",strlen(p));
	
	return 0;
}

