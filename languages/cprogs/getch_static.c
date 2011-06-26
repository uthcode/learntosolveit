/* modify getop so that it does not need to use ungetch: Hint: static int lastc */

#include<stdio.h>
#include<stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
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
					push(pop()+pop());
					break;
			case '*':
					push(pop()*pop());
					break;
			case '-':
					op2=pop();
					push(pop()-op2);
					break;
			case '/':
					op2=pop();
					if(op2 != 0.0)
						push(pop()/op2);
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


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push : push f onto value stack */

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
	if(sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include<ctype.h>

int getch(void);

/* getop: get next operator or numeric operand */

int getop(char s[])
{
	int c,i;
	static int lastc = 0;

	if(lastc == 0)
		c = getch();
	else
	{
		c = lastc;
		lastc = 0;
	}

	while((s[0]=c) == ' ' || c == '\t')
		c = getch();
	
	s[1]='\0';
	
	if(!isdigit(c) && c!= '.')
		return c;
	
	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] =c=getch()))
			;
	if(c=='.')
		while(isdigit(s[++i] =c=getch()))
			;
	s[i]='\0';
	
	if(c!=EOF)
		lastc=c;

	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

