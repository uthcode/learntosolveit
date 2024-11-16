/* Expand dcl to handle declarations with function argument types,qualifiers like const and so on */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

enum { NAME, PARENS, BRACKETS};
enum { NO, YES };

void dcl(void);
void dirdcl(void);
void errmsg(char *);


int gettoken(void);
extern int tokentype;	/* type of last token */
extern char token[];	/* last token string */
extern char name[];	/* identifier name */
extern char datatype[];	/* data type = char,int, etc */
extern char out[];
extern int prevtoken;

/* dcl: parse a declarator */

void dcl(void)
{
	int ns;
	
	for(ns = 0; gettoken() == '*'; )	/* count *'s */
		ns++;
	dirdcl();
	while(ns-- > 0)
		strcat(out,"pointer to");
}

/* dirdcl: parse a direct declaration */
void dirdcl(void)
{
	int type;
	void parmdcl(void);

	if(tokentype == '(')	/* (dcl)	*/
	{
		dcl();
		if( tokentype != ')')
			errmsg("error: missing ) \n");
	}
	else if(tokentype == NAME)	
	{
		if(name[0] == '\0')
			strcpy(name,token);
	}
	else
		prevtoken = YES;
	
	while((type = gettoken()) == PARENS || type == BRACKETS || type == '(')
		if( type == PARENS)
			strcat(out,"function returning");
		else if (type == '(')
		{
			strcat(out,"function expecting");
			parmdcl();
			strcat(out,"and returning");	
		}
		else
		{
			strcat(out,"array");
			strcat(out,token);
			strcat(out,"of");
		}
}

/* errmsg: print error message and indicate avail. token */
void errmsg(char *msg)
{
	printf("%s",msg);
	prevtoken = YES;
}


/* The source file parmdcl.c */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXTOKEN 100

void dcl(void);
void errmsg(char *);
void dclspec(void);
int compare(char **,char **);
int gettoken(void);
extern int tokentype;	/* type of last token */
extern char token[];	/* last token string */
extern char name[];	/* identifier name */
extern char datatype[];	/* data type = char, int etc */
extern char out[];
extern int prevtoken;

/* parmdcl: parse a parameter declarator */

void parmdcl(void)
{
	do
	{
		dclspec();
	}while ( tokentype == ',');
	
	if(tokentype != ')')
		errmsg("missing ) in parameter declaration \n");
}

/* compare: compare two strings for bsearch */

int compare(char **s,char **t)
{
    return strcmp(*s,*t);
}



/* typequal: return YES if token is a type-qualifier */
int typequal(void)
{
    static char *typeq[] =
            {
                    "const",
                    "volatile"
            };

    char *pt = token;

    if(bsearch(&pt,typeq,sizeof(typeq)/sizeof(char *),sizeof(char *),(int *) compare) == NULL)
        return NO;
    else
        return YES;
}



/* typespec: return YES if token is a type-specifier	*/
int typespec(void)
{
    static char *types[] =
            {
                    "char",
                    "int",
                    "void"
            };

    char *pt = token;

    if(bsearch(&pt,types,sizeof(types)/sizeof(char *),sizeof(char *), (int *) compare) == NULL)
    return NO;
    else
    return YES;
}


/* dclspec: declaration specification */

void dclspec(void)
{
	char temp[MAXTOKEN];

	temp[0] = '\0';
	gettoken();

	do
	{
		if(tokentype != NAME)
		{
			prevtoken = YES;
			dcl();
		}
		else if(typespec() == YES)
		{
			strcat(temp," ");
			strcat(temp,token);
			gettoken();
		}
		else if(typequal() == YES)
		{
			strcat(temp," ");
			strcat(temp,token);
			gettoken();
		}
		else
			errmsg("unknown type in parameter list \n");
	}while (tokentype != ',' && tokentype != ')');

	strcat(out,temp);
	if(tokentype == ',')
		strcat(out,",");
}


