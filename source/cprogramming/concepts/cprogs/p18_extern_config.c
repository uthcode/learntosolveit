#include<stdio.h>
#include "config.h"

/**
 * $ gcc p18_extern_config.c config.c -o p18_extern_config
 * $ ./p18_extern_config
 * Max connections: 100
 **/

int main(int argc, char *argv[]) {
    init_config();
    printf("Max connections: %d\n", app_config.max_connections);
    return 0;
}