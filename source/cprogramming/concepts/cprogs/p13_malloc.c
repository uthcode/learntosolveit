#include<stdio.h>
#include<stdlib.h>

#define COLS 5


int main(int argc, char *argv[]) {

    typedef int RowArray[COLS];
    RowArray *rptr;

    int nrows = 10;
    int row, col;

    rptr = malloc(nrows * COLS * sizeof(int));

    for (row = 0; row < nrows; row++) {
        for (col = 0; col < COLS; col++) {
            rptr[row][col] = row * col;
        }
    }

    free(rptr);
    return 0;
}