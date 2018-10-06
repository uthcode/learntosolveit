/***
 *
 * Write a program to count blanks, tabs and newlines.
 *
 **/

#include<stdio.h>

int main() {

    int char_count, num_lines, num_tabs, num_spaces;


    num_lines = 0;
    num_tabs = 0;
    num_spaces = 0;

    while ((char_count = getchar()) != EOF) {
        if (char_count == '\n')
            ++num_lines;
        if (char_count == '\t')
            ++num_tabs;
        if (char_count == ' ')
            ++num_spaces;
    }

    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", num_spaces, num_tabs, num_lines);

}
