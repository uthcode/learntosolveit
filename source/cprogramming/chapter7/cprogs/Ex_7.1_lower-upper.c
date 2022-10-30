/* Write a program which converts upper case to lower case or lower case to 
upper case depending on the name it is involved with as found in argv[0] */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* lower: converts upper case to lower case */
/* upper: converts lower case to upper case */

int main(int argc,char *argv[])
{
	int c;

	if(strcmp(argv[0],"./lower")==0)
		while((c=getchar()) != EOF)
			putchar(tolower(c));
	else
		while((c=getchar()) != EOF)
			putchar(toupper(c));

	return 0;
}

