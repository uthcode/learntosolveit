/***
 *
 * Write a program to count blanks, tabs and newlines.
 *
 **/

#include <stdio.h>

const char *input = "This\tis\ta\ttest\\string\bwith\ttabs\\and\\backspaces.\n\nnewline";
int input_index = 0;

int custom_getchar(void) {
    if (input[input_index] == '\0') {
        return EOF;
    } else {
        return input[input_index++];
    }
}

int main()
{
    int c, blanks, tabs, newlines;

    blanks = tabs = newlines = 0;

    while ((c = custom_getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++newlines;
    }

    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);
}
