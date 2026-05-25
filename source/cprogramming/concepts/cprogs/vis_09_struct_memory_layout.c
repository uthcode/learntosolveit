/* Visualization: struct fields at consecutive addresses; nested structs compose */
#include <stdio.h>
struct point { int x; int y; };
struct rect  { struct point ul; struct point lr; };
int main(void) {
    struct rect r = {{1, 2}, {5, 6}};
    printf("ul=(%d,%d)  lr=(%d,%d)\n", r.ul.x, r.ul.y, r.lr.x, r.lr.y);
    printf("sizeof(point)=%zu  sizeof(rect)=%zu\n",
           sizeof(struct point), sizeof(struct rect));
    return 0;
}
