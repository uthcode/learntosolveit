/**
 * Exercise 1.16
 *
 * Write a program to print the length of an arbitrarily long input line
 * and as much text as possible
 *
 **/

#include <stdio.h>

/* The size of the output that we would like */
#define MAX 1000

/* define our functions*/
int get_line(char arr[], int lim);

void copy(char to[], const char from[]);

int main() {

    int len, max;
    char line[MAX];
    char longest[MAX];

    max = 0;
    while ((len = get_line(line, MAX)) > 0) {

        if (len > max) {

            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {

        printf("length = %i, string=%s", max, longest);
    }

    return 0;
}

/* get a line in a character array */
int get_line(char arr[], int lim) {

    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {

        arr[i] = c;
    }
    if (c == '\n') {

        arr[i] = c;
        ++i;

    } else {

        /* Continue to count the length even if it is longer than the max */
        while ((c = getchar() != EOF) && c != '\n') {

            ++i;
        }

        if (c == '\n') {

            arr[i] = c;
            ++i;
        }
    }

    arr[i] = '\0';
    return i;
}

/* copy one character array to another */
void copy(char to[], const char from[]) {

    int i;

    i = 0;

    while ((to[i] = from[i]) != '\0') {

        ++i;
    }
}
