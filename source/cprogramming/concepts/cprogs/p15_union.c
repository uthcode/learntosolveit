#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main(int argc, char *argv[]) {
    union Data data;
    union Data *ptr;

    ptr = &data;

    data.i  = 42;
    printf("Integer value: %d \n", data.i);

    ptr->f = 3.14;
    printf("Float value: %f\n", data.f);

    printf("Integer value again: %d \n", data.i);
    printf("Since Union share memory, the integer value is lost.");
}