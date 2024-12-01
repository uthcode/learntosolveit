#include <stdio.h>
#include "other.h"

// Declare the external variable
extern int shared_value;        // This tells compiler variable is defined elsewhere
extern void modify_value(void); // Declare external function

int main(int argc, char *argv[]) {
    printf("Initial shared value: %d\n", shared_value);


    // Modify the value in main
    shared_value = 20;
    printf("After modifying the value in main: %d\n", shared_value);


    modify_value();
    printf("After calling modify_value: %d\n", shared_value);

    return 0;
}