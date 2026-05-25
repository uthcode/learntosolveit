/* Concept: getline loop written without && or || */
#include <stdio.h>
void copy(char to[], const char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}
int main(void) {
    char *data[2] = {"hi", "hello"};
    char line[10], maxline[10];
    int len, max = 0, i, j;
    for (i = 0; i < 2; ++i) {
        for (j = 0; data[i][j] && j < 9; j++) line[j] = data[i][j];
        line[j] = '\0'; len = j;
        if (len > max) { max = len; copy(maxline, line); }
    }
    if (max > 0) printf("%s\n", maxline);
}
