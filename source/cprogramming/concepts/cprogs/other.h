#ifndef LEARNTOSOLVEIT_OTHER_H
#define LEARNTOSOLVEIT_OTHER_H

#include <stdio.h>
int shared_value = 10;

void modify_value(void) {
    shared_value *= 2;
    printf("Modified in other.h : %d\n", shared_value);
}

#endif //LEARNTOSOLVEIT_OTHER_H
