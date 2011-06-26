#include<stdio.h>

int strend(char *,char *);

/* strend: return 1 is the string t occurs at the end of s */

int main(void)
{
	char *s="This is a string";
	char *t="string";
	int ret;

	ret=strend(s,t);
	
	printf("%d",ret);
	
	return 0;
}

int strend(char *s,char *t)
{
	char *bs=s;
	char *bt=t;

	for( ; *s; s++)
		;
	for( ; *t; t++)
		;

	for(; *s == *t; s--,t--)
		if(t==bt || s==bs)
			break;
	if(*s==*t && t==bt && *s!='\0')
		return 1;
	else
		return 0;
}


		
	
