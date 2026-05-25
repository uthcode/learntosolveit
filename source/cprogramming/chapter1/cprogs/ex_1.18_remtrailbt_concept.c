/* Concept: remove trailing blanks by scanning backwards */
#include <stdio.h>
int main(void) {
    char s[] = "hi   ";
    int i = 0, end;
    while (s[i]) i++;
    end = i - 1;
    while (end >= 0 && (s[end] == ' ' || s[end] == '\t')) end--;
    s[end + 1] = '\0';
    printf("'%s'\n", s);
    return 0;
}
