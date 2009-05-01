/* Modify the programs entab and detab  to accept the list of tab stops as 
   arguments. Use default tab settings if no arguments are used */

/* modentab.c */
#include<stdio.h>

#define MAXLINE 100	/* maximum line size */
#define TABINC	8	/* default tab increment size */
#define YES 	1
#define	NO	0

void settab(int argc,char *argv[],char *tab);
void entab(char *tab);
int tabpos(int pos,char *tab);

/* replace strings of blanks with tabs */

int main(int argc,char *argv[])
{
	char tab[MAXLINE+1];
	settab(argc,argv,tab);	/* intialize tab stops */
	entab(tab);		/* replace blanks with tabs */
	return 0;
}

/* entab: replace strings of blanks with tabs and blanks */
void entab(char *tab)
{
	int c,pos;
	int nb = 0;	/* # of blanks necessary */
	int nt = 0;	/* # of tabs necessary */
	
	for(pos=1;(c=getchar())!=EOF;pos++)
		if(c == ' ')
		{
			if(tabpos(pos,tab)== NO)
				++nb;	/* increment # of blanks */
			else
			{
				nb = 0;
				++nt;	/* one more tab */
			}
		}
		else
		{
			for(;nt > 0;nt--)
				putchar('\t');	/* output of tabs(s)	*/
			if(c == '\t')
				nb = 0;
			else
				for(;nb > 0;nb--)
					putchar(' ');
			putchar(c);
			
			if(c == '\n')
				pos = 0;
			else if( c == '\t')
				while(tabpos(pos,tab) != YES)
					++pos;
		}
}

/* settab.c */

void settab(int argc,char *argv[],char *tab)
{
	int i,pos;
	
	if(argc <= 1)	/* default tab stops */
		for(i = 1; i <= MAXLINE;i++)
			if(i % TABINC == 0)
				tab[i] = YES;
			else
				tab[i] = NO;
		else
		{
			/* user provided tab stops */
			for(i = 1;i <= MAXLINE; i++)
				tab[i] = NO;
			while(--argc > 0)
			{
				pos = atoi(*++argv);
				if(pos > 0 && pos <= MAXLINE)
					tab[pos] = YES;
			}
		}
}

/* tabpos.c */

int tabpos(int pos,char *tab)
{
	if(pos > MAXLINE)
		return YES;
	else
		return tab[pos];
}

