/* Concept: tab stop array — tabstop[col]=1 marks where tabs expand to */
#include <stdio.h>
int main(void) {
    int tabstop[9] = {0,0,0,0,1,0,0,0,1}; /* stops at col 4 and 8 */
    int col;
    for (col = 0; col <= 8; col++)
        printf("col %d: tabstop=%d\n", col, tabstop[col]);
    return 0;
}
