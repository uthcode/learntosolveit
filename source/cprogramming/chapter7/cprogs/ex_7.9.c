/*
 * Functions like isupper can be implemented to save space or to save time.
 * Explore both possibilities.
 */

#include <stdio.h>
#include <stdlib.h>

int myisupper(int);

const char *input = "AbCdEfx";
int input_index = 0;

int custom_getchar(void) {
    if (input[input_index] == '\0') {
        return EOF;
    } else {
        return input[input_index++];
    }
}


int main(void) {
    int c;

    while ((c = custom_getchar()) != 'x') {
        if (c == '\n')
            continue;

        if (myisupper(c) == 1)
            printf("true\n");
        else
            printf("false\n");
    }
    return EXIT_SUCCESS;
}

int myisupper(int c) {
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}
