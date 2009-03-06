#include<stdio.h>
int strindex(char *s,char *t);

int main(void)
{
	char *s="This is a line";
	char *t="is";
	int ret;

	ret=strindex(s,t);
	printf("%d",ret);

	return 0;
}

int strindex(char *s,char *t)
{
	char *b=s;
	char *p,*r;

	for(;*s!='\0';s++)
	{
		for(p=s,r=t;*r!='\0' && *p==*r;p++,r++)
			;

			if(r>t && *r == '\0')
				return s-b;
	}
	return -1;
}
