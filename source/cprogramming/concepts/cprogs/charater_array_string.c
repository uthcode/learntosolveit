#include<stdio.h>

int main(int argc, char *argv[]) {
    char s[]  = {'s', 't', 'r', 'i', 'n', 'g', '\0'};
    printf("%s\n", s);

    char s1[10];
    int i, j;
    for (i = 65, j = 0; i < 70; i++) {
        s1[j] = (char) i;
        j++;
    }
    s1[j] = '\0';

    printf("%s\n", s1);

    char s2[] = "string";

    printf("%s\n", s2);

}