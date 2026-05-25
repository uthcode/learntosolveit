/* Concept: DCL output — combine name, modifier, and datatype strings */
#include <stdio.h>
#include <string.h>
int main(void) {
    /* Simulates parsing "int *p" → name="p", out=" pointer to", datatype="int" */
    char datatype[] = "int";
    char name[]     = "p";
    char out[]      = " pointer to";
    printf("%s%s %s\n", name, out, datatype);
    /* Simulates parsing "char (*fp)()" */
    printf("%s%s %s\n", "fp", " pointer to function returning", "char");
    return 0;
}
