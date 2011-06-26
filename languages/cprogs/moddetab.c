/* moddetab.c */
#include<stdio.h>
#define MAXLINE 100
#define TABINC	8
#define YES	1
#define NO	0

void settab(int argc,char *argv[],char *tab);
void detab(char *tab);
int tabpos(int pos,char *tab);

/* replace tabs with blanks */

int main(int argc,char *argv[])
{
	char tab[MAXLINE+1];
	settab(argc,argv,tab);
	detab(tab);
	return 0;
}

/* detab: replace tabs with blanks */

void detab(char *tab)
{
	int c,pos = 1;

	while((c=getchar())!= EOF)
		if(c == '\t')
		{
			do
				putchar(' ');
			while(tabpos(pos++,tab)!=YES);
		}
		else if(c == '\n')
		{
			putchar(c);
			pos =1 ;
		}
		else
		{
			putchar(c);
			++pos;
		}
}

/* settab: set tab stops in array tab */

void settab(int argc,char *argv[],char *tab)
{
	int i,pos;
	
	if(argc <= 1)	/* default tab stop */
		for(i =1;i<=MAXLINE;i++)
			if(i%TABINC == 0)
				tab[i] = YES;
			else
				tab[i] = NO;
		else
		{
			/* user provided tab stops */
			for(i =1; i<=MAXLINE;i++)
				tab[i] = NO; /* turn off all tab stops */
			while(--argc > 0)
			{
				pos = atoi(*++argv);
				if(pos > 0 && pos <= MAXLINE)
					tab[pos] = YES;
			}
		}
}

/* tabpos.c : determine if pos is at a tab stop */

int tabpos(int pos,char *tab)
{
	if( pos > MAXLINE)
		return YES;
	else
		return tab[pos];
}

