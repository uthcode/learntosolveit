#include <stdio.h>
#include <limits.h>

/**
 * %b specifier is available since C23
 * https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2630.pdf
 * if %b is not available for your compiler
 * we can use print_bin to see the binary
 **/

void print_bin(unsigned char byte)
{
    int i = CHAR_BIT; /* however many bits are in a byte on your platform */
    while(i--) {
        putchar('0' + ((byte >> i) & 1)); /* loop through and print the bits */
    }
}

int main(int argc, char *argv[]) {
    unsigned char a = 12 ; // Binary 00001100
    unsigned char b = 10;  // Binary 00001010

    printf("Original Values: \n");
    printf("a = %d (Binary: %08b)\n", a, a);
    printf("b = %d (Binary: %08b)\n", b, b);

    printf("Decimal %d in Binary is", a);
    print_bin(a);

    printf("\n");

    printf("Decimal %d in Binary is", b);
    print_bin(b);

    // Bitwise AND (&)
    printf("\n Bitwise AND (&): \n");
    printf("%d & %d = %d (binary: %08b)\n", a, b, a & b, a & b);


    // Bitwise OR (|)
    printf("\n Bitwise OR (|): \n");
    printf("%d | %d = %d (binary: %08b)\n", a, b, a | b, a | b);

    // Bitwise XOR (^)
    printf("\n Bitwise XOR (^): \n");
    printf("%d ^ %d = %d (binary: %08b)\n", a, b, a ^b, a ^b);

    // Left shift <<
    printf("\n Left Shift (<<): \n");
    printf("%d << 1 = %d (binary: %08b)\n", a, a << 1, a << 1);

    // Right shift >>
    printf("\n Right Shift (>>): \n");
    printf("%d >> 1 = %d (binary: %08b)\n", a, a >> 1, a >> 1);

    // Bitwise NOT (~)
    printf("\n Bitwise NOT (~) \n");
    printf("~%d = %d (binary: %08b)\n", a, (unsigned char) ~a, (unsigned char)~a);
}