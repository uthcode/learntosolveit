/* Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 1000
void mystrncpy(char *s,char *t,int n);
void mystrncat(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);

int mystrlen(char *s);

int main(int argc, char *argv[])
{
    
    char s[]="ABCDEF";
    char t[]="GHIJ";

    /*TODO:
    Make it work for
    char *s = "abcd";
    char *t = "efgh";
    */

    mystrncpy(s,t,4);
    printf("%s\n",s);

    char s1[] = "ABCD";

    mystrncat(s1,t,4);
    printf("%s\n", s1);

    char s2[]= "ABCDEF";
    char t2[]= "ABC";
    int result;

    result = mystrncmp(s2,t2,3);

    printf("%d\n", result);


    return 0;
}

void mystrncat(char *s, char *t, int n) {
	/* We are advancing the pointer in s*/
	/* Figure out how to advance the pointer properly */
	mystrncpy(s, t, n);
}

void mystrncpy(char *s,char *t,int n)
{
    while(*t && n-- > 0)
        *s++ = *t++;

    int extra = mystrnlen(s) - n;

    while (extra-- > 0) {
    	*s++;
    }

    *s = '\0';
}

/* mystrcmp: return <0 if s <t , 0 if s==t, > 0 if s > t */
int mystrncmp(char *s,char *t, int n)
{
    for(; *s == *t; s++,t++)
        if( *s == '\0' || --n <=0)
            return 0;
    return *s - *t;

}


int mystrnlen(char *s) {
	char *p = s;
	while (*s != '\0') {
		s = s + 1;
	}
	return s - p;
}
