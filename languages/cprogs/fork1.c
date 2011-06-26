#include <stdio.h>

int main()
{
    int pid;
    pid = fork();
    printf("%d \n",pid);
}
