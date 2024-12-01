#ifndef MY_PROGRAM_HEADER
#define MY_PROGRAM_HEADER

#define SQUARE(x) ((x) * (x))
#define WINDOWS 1
#define LINUX 2
#define PLATFORM LINUX

#include <stdio.h>

int main(int argc, char *argv[]) {
    int num = 20;
    printf("Square of the number is %d\n", SQUARE(num));

    // Conditinal Compilation

#ifdef PLATFORM
#if PLATFORM == WINDOWS
    printf("Compiling for Windows\n");
#define PATH_SEPARATOR "\\"
#elif PLATFORM == LINUX
    printf("Compiling for Linux\n");
#endif
#define PATH_SEPARATOR "/"
#else
#error Platform not defined!
#endif

}

#endif // MY_PROGRAM_HEADER