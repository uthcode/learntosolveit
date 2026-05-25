/* Concept: recursive directory walk — visit each file entry */
#include <stdio.h>
struct entry { char *name; int is_dir; long size; };
void dirwalk(struct entry entries[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (entries[i].is_dir) printf("[%s/]\n", entries[i].name);
        else printf("%s (%ld bytes)\n", entries[i].name, entries[i].size);
    }
}
int main(void) {
    struct entry entries[] = {
        {"file1.c", 0, 1024},
        {"subdir",  1, 0},
        {"main.c",  0, 512},
    };
    dirwalk(entries, 3);
    return 0;
}
