/* Concept: external (global) variables shared between functions */
#include <stdio.h>
int max;
char longest[10];
char line[10];
void copy(void);
int main() {
    extern int max;
    extern char longest[], line[];
    char *inputs[2] = {"hi", "hello"};
    int i, len;
    max = 0;
    for (i = 0; i < 2; ++i) {
        len = 0;
        while (inputs[i][len]) { line[len] = inputs[i][len]; len++; }
        line[len] = '\0';
        if (len > max) { max = len; copy(); }
    }
    printf("%s\n", longest);
    return 0;
}
void copy(void) {
    extern char line[], longest[];
    int i = 0;
    while ((longest[i] = line[i]) != '\0') ++i;
}
