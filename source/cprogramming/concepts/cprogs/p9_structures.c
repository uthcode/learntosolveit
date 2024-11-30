#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct tag {
        char lname[20];
        char fname[20];
        int age;
        float rate;
    };

    struct tag my_struct;

    strcpy(my_struct.lname, "Kumaran");
    strcpy(my_struct.fname, "Senthil");

    printf("\n%s ", my_struct.fname);
    printf("%s\n", my_struct.lname);

    return 0;
}

