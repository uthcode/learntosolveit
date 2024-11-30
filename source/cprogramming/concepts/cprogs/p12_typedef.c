#include<stdio.h>

int main(int argc, char *argv[]) {
    typedef unsigned char byte;

    byte b[] = {'b', 'y', 't', 'e', '\0'};

    printf("%s", b);
}