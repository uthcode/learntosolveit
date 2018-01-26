/**
 *
 * Exercise 1.11 - Write a program that prints its input one word per line.
 *
 * */

#include<stdio.h>

int main() {
    int _char;

    _char = getchar();

    while (_char != EOF) {

        if (_char == ' ') {
            putchar('\n');
        }
        else {
            putchar(_char);
        }

        _char = getchar();
    }
}
