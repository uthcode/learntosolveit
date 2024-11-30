#include <stdio.h>

#define ROWS 5
#define COLS 10

int main(int argc, char *argv[]) {
    int multi[ROWS][COLS];

    int row, col;

    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            multi[row][col] = row * col;
        }
    }

    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("\n%d ", multi[row][col]);
            printf("%d ", *(*(multi + row) + col));
        }
    }
}