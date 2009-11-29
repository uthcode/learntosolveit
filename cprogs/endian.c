#include<stdio.h>
int main(int argc, char *argv[])
{
	int a=0x99000011;
	unsigned char *c = (unsigned char *) (&a);
	if (*c == 0x11)
		printf("little endian\n");
	else
		printf("big endian\n");

}
