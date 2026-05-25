/* Concept: undcl builds declaration string by prepending * for "pointer to" */
#include <stdio.h>
#include <string.h>
int main(void) {
    char out[40], temp[40];
    /* "p pointer to int" -> "int *p" */
    strcpy(out, "p");
    sprintf(temp, "*%s", out);
    strcpy(out, temp);
    printf("int %s\n", out);
    /* "fp pointer to function returning char" -> "char (*fp)()" */
    strcpy(out, "fp");
    sprintf(temp, "(*%s)()", out);
    strcpy(out, temp);
    printf("char %s\n", out);
    return 0;
}
