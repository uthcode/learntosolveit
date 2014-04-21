/* Ex5.6 */

#include<stdio.h>
#include<stdlib.h>	

#define MAXOP 100
#define NUMBER '0'

int getop(char *);
void push(double);
double pop(void);

/* reverse polish calculator */

int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
					push(atof(s));
					break;
			case '+':
					push(pop() + pop());
					break;
			case '*':
					push(pop() * pop());
					break;
			case '-':
					op2 = pop();
					push(pop() - op2);
					break;
			case '/':
					op2 = pop();
					if( op2 != 0.0)
						push(pop() / op2);
					else
						printf("error: zero divisor\n");
					break;
			case '\n':
					printf("\t%.8g\n",pop());
					break;
			default:
					printf("error: unknown command %s\n",s);
					break;
		}
	}
	return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full,can't push %g\n",f);
}

/* pop: pop and return top value from stack */

double pop(void)
{
	if( sp > 0)	
		return val[--sp];
	else
	{
		printf("error: stack empty \n");
		return 0.0;
	}
}

/* getop: get next operator or numeric operand  pointer version */

#include<ctype.h>
#define NUMBER '0' /* signal that a number was found */

int getch(void);
void ungetch(int);

int getop(char *s)
{
	int c;
	
	while((*s=c=getch()) == ' ' || c == '\t')
		;
	*(s+1) = '\0';

	if(!isdigit(c) && c!='.')
		return c;		/* not a number */
	if(isdigit(c))
	while(isdigit(*++s = c = getch()))
		;

	if(c == '.')
	while(isdigit(*++s = c = getch()))
		;

	*s = '\0';

	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp]:getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++]=c;
}

		




















 
