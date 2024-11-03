/* Write a program which converts upper case to lower case or lower case to
upper case depending on the name it is involved with as found in argv[0] */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* lower: converts upper case to lower case */
/* upper: converts lower case to upper case */

const char *input = "This\tis\ta\ttest";
int input_index = 0;

int _getchar(void) {
    if (input[input_index] == '\0') {
        return EOF;
    } else {
        return input[input_index++];
    }
}



int main(int argc, char *argv[]) {
    int c;

    if (strcmp(argv[0], "./lower") == 0)
        while ((c = _getchar()) != EOF)
            putchar(tolower(c));
    else
        while ((c = _getchar()) != EOF)
            putchar(toupper(c));

    return 0;
}
