/* Concept: count characters with for loop */
#include <stdio.h>
int main() {
    char s[] = "hi\n";
    double nc;
    int i = 0;
    for (nc = 0; s[i++]; ++nc);
    printf("%.0f\n", nc);
}
