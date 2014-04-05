#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 1000
void mystrncpy(char *s,char *t,int n);
char * mystrncat(char *s, char *t, int n);

int main(void)
{
    
    char *s="This is a string";
    char *t="Another String";

    if ((s = (char *) malloc(sizeof(char) * strlen(t) + strlen(s))) == NULL) {
        printf("unable to allocate memory \n");
        return -1;
    }

    mystrncpy(s,t,10);
    printf("%s\n",s);
    free(s);

    char *s1="ABCDEF";
    char *t1="ABCDEF";
    char *r = mystrncat(s1, t1, 3);
    printf("%s", r); /* ABCABC */

    //char *s="ABCD";
    //char *t="ABC";
    //int result;
    //result = mystrncmp(s,t, 3);
    //printf("%d", result); /* 0 */

    return 0;
}

void mystrncpy(char *s,char *t,int n)
{
    while(*t && n-- > 0)
        *s++ = *t++;

    while(n-- > 0)
        *s++ = '\0';
}

char * mystrncat(char *s, char *t, int n) 
{
    char *r;

    if ((r = (char *) malloc(sizeof(char) * strlen(s) + strlen(t))) == NULL) {
        printf("unable to allocate memory \n");
        return -1;
    }

    int orig_n = n;

    while(*s && n-- > 0)
        *r++ = *s++;

    if (n == 0) {
        while(*t && orig_n-- > 0)
            *r++ = *t++;
    }

    while(orig_n-- > 0)
        *r++='\0';

    return r;
}

