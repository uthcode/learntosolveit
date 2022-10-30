/* a macro swap(t,x,y) that interchanges two arguments of type t */

#include <stdio.h>

#define swap(t, x, y)                                                          \
    {                                                                          \
        t _z;                                                                  \
        _z = x;                                                                \
        x = y;                                                                 \
        y = _z;                                                                \
    }

int main(void) {
    char x, y;
    x = 'a';
    y = 'b';
    printf("x= %c \t y= %c\n", x, y);
    swap(char, x, y);
    printf("x=%c \t y=%c\n", x, y);
}
