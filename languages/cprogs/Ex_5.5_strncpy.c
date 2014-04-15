/* Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 1000
void mystrncpy(char *s,char *t,int n);

int main(int argc, char *argv[])
{
    
    char s[6]="ABCDEF";
    char t[6]="GHIJ";

    /*TODO:
    Make it work for
    char *s = "abcd";
    char *t = "efgh";
    */

    mystrncpy(s,t,4);
    printf("%s\n",s);

    return 0;
}

void mystrncpy(char *s,char *t,int n)
{

	int mystrlen(char *s);

    while(*t && n-- > 0)
        *s++ = *t++;

    int extra = mystrnlen(s) - n;

    while (extra-- > 0) {
    	*s++;
    }

    *s = '\0';
}

int mystrnlen(char *s) {
	char *p = s;
	while (*s != '\0') {
		s = s + 1;
	}
	return s - p;
}
