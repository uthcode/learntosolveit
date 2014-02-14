#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
/* reverse Polish calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
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
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
			case '\n':
			printf("\t%.8g\n", pop());
			break;
			default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}