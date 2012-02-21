/**
Write a program to determine the ranges of char , short , int , and long
variables, both signed and unsigned , by printing appropriate values from
standard headers and by direct computation. Harder if you compute them:
determine the ranges of the various floating-point types

IMPORTANT:
compile with gcc -std=c99 <program_name>

std=c99 for long long int types.

Program written under
Hardware Name:	i686
Processor:	i686
Hardware Platform:i386
*/

#include<limits.h>
#include<stdio.h>

int main(void)
{
	printf("Minimum value - Singed Char : %d\n",SCHAR_MIN);
	printf("Maximum value - Signed Char : %d\n",SCHAR_MAX);
	printf("Maximum value - Unsigned Char : %d\n",UCHAR_MAX);

	printf("Minimum value - Signed Short Int : %d\n",SHRT_MIN);
	printf("Maximum value - Signed Short Int : %d\n",SHRT_MAX);
	printf("Maximum value - Unsigned Short Int : %d\n",USHRT_MAX);

	printf("Minimum value - Signed Int : %d\n",INT_MIN);
	printf("Maximum value - Signed Int : %d\n",INT_MAX);
	printf("Maximum value - Unsigned Int : %u\n",UINT_MAX);

	printf("Minimum value - Signed long int : %ld\n",LONG_MIN);
	printf("Maximum value - Signed long int : %ld\n",LONG_MAX);
	printf("Maximum value - Unsigned long int : %lu\n",ULONG_MAX);

	printf("Minimum value - Signed long long int: %lld\n",LLONG_MIN);
	printf("Maximum value - Signed long long int: %lld\n",LLONG_MAX);
	printf("Maximum value - Unsigned long long int : %llu\n",ULLONG_MAX);

	return 0;
}

