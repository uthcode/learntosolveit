/**
 * 
 * Program Description: write system call
 * 
 * Date: 6/24/18
 **/

#include <unistd.h>

int main(int argc, char *argv[]) {
    write(1, "Hello\n", 6);
    write(1, "World\n", 6);
}
