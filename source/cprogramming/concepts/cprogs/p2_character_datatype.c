#include <stdio.h>

int main(int argc, char *argv[]) {
    char char_value;
    char_value = 'c';
    printf("The value of my character datatype is %c\n", char_value);

    int i = 0;
    for (i = 0; i <128; i++) {
        char_value = (char) i;
        printf("The value of my character datatype is %c for the integer value %d \n", char_value, i);
    }
}