/**
 * Exercise 1.22
 *
 * Write a method fold, to fold long lines after a specified Column
 *
 ** /

#include<stdio.h>

#define MAXCOL 50
#define TABVAL 8

char line[MAXCOL];
int expandtab(int pos);
int printline(int pos);
int getblank(int pos);
int newposition(int pos);

int main(void)
{
	int pos,c;
	pos = 0;

	while((c=getchar())!=EOF)
	{
		line[pos] = c;

		if( c == '\t')
			pos = expandtab(pos);
		if( c == '\n')
		{
			printline(pos);
			pos = 0;
		}
		else if( ++pos >= MAXCOL )
		{
			pos = getblank(pos);
			printline(pos);
			pos = newposition(pos);
		}
	}
	return 0;
}

int expandtab(int pos)
{
	line[pos] = ' ';

	for(++pos; (pos < MAXCOL)&&((pos % TABVAL)!= 0); ++pos)
	line[pos] = ' ';

	if( pos >= MAXCOL)
	{
		printline(pos);
		return 0;
	}
	else
		return pos;
}

int printline(int pos)
{
	int i;
	for(i = 0; i < pos; ++i)
		putchar(line[i]);
	if( pos > 0)
		putchar('\n');
	return 0;
}

int getblank(int pos)
{
	if( pos > 0)
		while( line[pos] != ' ')
			--pos;
	if(pos == 0)
		return MAXCOL;
	else
		return pos + 1;
}
int newposition( int pos)
{
	int i,j;

	if(pos <= 0 || pos >= MAXCOL)
		return 0;
	else
	{
		i = 0;
		for(j=pos;j < MAXCOL; ++j,++i)
		line[i] = line[j];	
	}
	return i;
}
	

	
